
/* Controller Area Network (bxCAN) */

#define hw_setbits(status, mask) status |= (mask)
#define hw_clrbits(status, mask) status &= ~(mask)
#define hw_waitset(status, mask) while (((status) & (mask)) != (mask))
#define hw_waitclr(status, mask) while (!((status) & (mask)))

#include <stdint.h>

struct can_device {
	CAN_TypeDef *pcan;
	GPIO_TypeDef *pio;
};

union can_identity {
	struct {
		uint32_t :1; /* reserved */
		uint32_t rtr:1; /* remote transmition req */
		uint32_t ide:1; /* whether extended message */
		uint32_t exid:28; /* id or exid */
	} bits;
	uint32_t word;
};

union can_lents {
	struct {
		uint32_t dlc:4;
		uint32_t :12;
	  	uint32_t ts:16;
	} bits;
	uint32_t word;
};

struct can_frame {
	union can_identity id;
	union can_lents lts;
	uint8_t data[8];
};

static struct can_device device_list[] = {
	{CAN1, 0}
};

void can_open(struct can_device *device)
{
	/* leave sleep mode */
	hw_clrbits(device->pcan->MCR, CAN_MCR_SLEEP)
	hw_waitclr(device->pcan->MSR, CAN_MSR_SLAK);
	/* enter initialization mode */
	hw_setbits(device->pcan->MCR, CAN_MCR_INRQ);
	hw_waitset(device->pcan->MSR, CAN_MSR_INAK);

	/* set CAN_BTR and CAN_MCR */

	/* returun to normal mode */
	hw_clrbits(device->pcan->MCR, CAN_MCR_INRQ);
	hw_waitclr(device->pcan->MSR, CAN_MSR_INAK);
}

int can_read(struct can_device *device, struct can_frame *frame, uint8_t count)
{
	uint8_t cnt0 = device->pcan->FMP0;
	uint8_t cnt1 = device->pcan->FMP1;
	uint8_t i;
	if (count > cnt1 + cnt0) {
		count = cnt1 + cnt0;
	}
	for (i = 0; i < cnt0; i++) {
		frame[i].id.word = device->pcan->sFIFOMailBox[0].RIR;
		frame[i].lts.word = device->pcan->sFIFOMailBox[0].RDTR;
	}
	return 0;
}

int can_write(struct can_device *device, struct can_frame *frame, uint8_t count)
{
	uint32_t tsr = device->pcan->TSR;
	int ret = 0;
	uint8_t mask[3] = {0};
	uint8_t i;
	if (CAN_TSR_RQCP0 & tsr) {
		if (ret < count) {
			mask[0] = 1;
			ret++;
		}
		
	}
	if (CAN_TSR_RQCP1 & tsr) {
		if (ret < count) {
			mask[1] = 1;
			ret++;
		}
	}
	if (CAN_TSR_RQCP2 & tsr) {
		if (ret < count) {
			mask[2] = 1;
			ret++;
		}
	}
	for (i = 0; i < 3; i++) {
		if (mask[i]) {
			uint32_t j;
			device->pcan->sTxMailBox[i].TIR = frame[ret].id.word;
			device->pcan->sTxMailBox[i].TDTR = frame[ret].lts.word;
			for (j = 0; j < frame[ret].lts.word; j++) {
				if (j < 8) {
					device->pcan->sTxMailBox[i].TDLR |= ((uint32_t)(frame[ret].data[j])) << ((j % 4) >> 3);
				} else {
					device->pcan->sTxMailBox[i].TDHR |= ((uint32_t)(frame[ret].data[j])) << ((j % 4) >> 3);
				}
			}
		}
	}
	return ret;
}

