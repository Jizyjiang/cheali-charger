
#include "Utils.h"

uint8_t selectIndexWithKeyboard(uint8_t &x, const uint8_t tab_size,  bool exactly)
{
	return setNumberWithKeyboard<uint8_t>(x, 0, tab_size - 1, 1, exactly);
}


bool testTinern(bool &more, AnalogInputs::ValueType off, AnalogInputs::ValueType on)
{
	AnalogInputs::ValueType t = analogInputs.getRealValue(AnalogInputs::Tintern);
	bool retu = false;
	if(t < off) {
		retu = true;
		more =  false;
	} else if(t > on) {
		retu = true;
		more = true;
	}
	return retu;
}

uint16_t pow10(uint8_t n)
{
	uint16_t retu = 1;
	while(n--) {
		retu*=10;
	}
	return retu;
}

uint8_t digits(uint16_t x)
{
	uint8_t retu = 0;
	if(x == 0)
		x=1;
	for(;x!=0; x/=10)
		retu++;
	return retu;
}


void changeMax(uint16_t &v, int direc, uint16_t max)
{
	uint16_t r;
	int step = 1;
	bool direction = direc > 0;

	uint8_t dv = digits(v);
	if(dv>1) step = pow10(dv-2);

	r = v%step;

	if(r) {
		if(direction) step -=r;
		else step = r;
	}
	if(direction) ADD_MAX(v, step, max);
	else SUB_MIN(v, step ,1);
}

