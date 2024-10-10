#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define IMG_HEIGHT 512
#define IMG_WIDTH 512

uint8_t** memory_alloc2D(uint32_t h, uint32_t w) //�޸� �Ҵ�
{
	uint8_t** pMem = new uint8_t * [h];
	if (pMem == 0)
		return 0;
	pMem[0] = new uint8_t[h * w];
	if (pMem[0] == 0)
	{
		delete[] pMem;
		return 0;
	}

	for (int i = 1; i < h; i++) {
		pMem[i] = pMem[i - 1] + w;
	}
	return pMem;
}

int memory_free2D(uint8_t** p) //�޸� ����
{
	if (p == 0)
		return -1;

	if (p[0])
		delete[] p[0];

	delete[] p;
	return 0;
}

int main()
{
	int i;
	FILE* fpinput = 0; //�б�� ���� 
	FILE* fpoutput = 0; //����� ����
	uint8_t** inputIMGBf = 0; //���� ������ ���������� ����
	const char* IMG_NAME = "Barbara_512x512_yuv400_8bit.raw"; //���� �̸� ����

	fpinput = fopen(IMG_NAME, "rb"); //���̳ʸ� �б� ���� ���� ����
	inputIMGBf = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH); //���ۿ� �̹��� �޸� �����Ҵ�

	for (i = 0; i < IMG_HEIGHT; i++) { //�̹��� ���̸�ŭ ���� �о����
		fread((uint8_t*)inputIMGBf[i], sizeof(uint8_t), IMG_WIDTH, fpinput);
	}

	//�̹��� ��ȯ �ܰ� �ڵ� (�̿ϼ�)


	/*�޸� �Ҵ� ����*/
	memory_free2D(inputIMGBf); 
	/*���� �ݱ�*/
	fclose(fpinput);
	fclose(fpoutput);

	return 0;
}