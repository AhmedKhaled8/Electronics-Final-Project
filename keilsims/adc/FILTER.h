#ifndef FILTER
#define FILTER

char FLITER_CTR = 19;

float idata inputSignal[19];
float idata outputSignal[19];

float code lpf_B[19] = {0.0009329, -0.01249, 0.07975, -0.3237, 0.9395, -2.083, 3.688, -5.398, 6.702, -7.188, 6.702, -5.398, 3.688, -2.083, 0.9395, -0.3237, 0.07975, -0.01249, 0.0009392};
float code lpf_A[19] = {1, -14.52, 99.82, -431.9, 1317, -3008, 5330, -7488, 8459, -7738, 5747, -3456, 1671, -640.2, 190.2, -42.27, 6.618, -0.6512, 0.03032};

float code hpf_B[6] = {0.99387, -4.969348, 9.93869, -9.93869, 4.96934, -0.99387};
float code hpf_A[6] = {1, -4.98769, 9.95087, -9.92643, 4.951035, -0.98777};


float code notch_B[11] = {0.97215, -9.68492, 43.45451, -115.6363, 202.1097, -242.43024, 202.1097, -115.6363, 43.4545, -9.68492, 0.972154571};
float code notch_A[11] = {1, -9.90605, 44.19583, -116.9456, 203.24584, -242.4194, 200.96285, -114.3331, 42.7231, -9.46841, 0.94508};


void LPF()
{
	
	char i;
	outputSignal[0] += (inputSignal[0] * lpf_B[0]);
	for(i = 1; i<19; i++)
	{
		outputSignal[0] += (outputSignal[i] * lpf_A[i] + inputSignal[i] * lpf_B[i]);
	}
}

void HPF()
{
	char i;
	outputSignal[0] += (inputSignal[0] * hpf_B[0]);
	for(i=1;i<6;i++)
	{
		outputSignal[0] += (outputSignal[i] * hpf_A[i] + inputSignal[i] * hpf_B[i]);
	}
}

void NOTCH()
{
	char i;
	outputSignal[0] += (inputSignal[0] * notch_B[0]);
	for(i=1;i<11;i++)
	{
		outputSignal[0] += (outputSignal[i] * notch_A[i] + inputSignal[i] * notch_B[i]);
	}
}

void SHIFT_REG(char CTR)
{
	char i;
	for(i=CTR-1;i>0;i--)
	{
		outputSignal[i] = outputSignal[i-1];
		inputSignal[i] = inputSignal[i-1];
	}
	outputSignal[0] = 0;
}

void RESET_REG()
{
	char i;
	for(i=0; i<19; i++)
	{
		outputSignal[i] = 0;
		inputSignal[i] = 0	;	
	}
}

#endif