#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define IMG_HEIGHT 512
#define IMG_WIDTH 512

uint8_t** memory_alloc2D(uint32_t h, uint32_t w) //메모리 할당
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

int memory_free2D(uint8_t** p) //메모리 해제
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
	FILE* fpinput = 0; //읽기용 파일 
	FILE* fpoutput = 0; //쓰기용 파일
	uint8_t** inputIMGBf = 0; //버퍼 저장할 이중포인터 형태
	const char* IMG_NAME = "Barbara_512x512_yuv400_8bit.raw"; //사진 이름 저장

	fpinput = fopen(IMG_NAME, "rb"); //바이너리 읽기 모드로 파일 오픈
	inputIMGBf = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH); //버퍼에 이미지 메모리 동적할당

	for (i = 0; i < IMG_HEIGHT; i++) { //이미지 높이만큼 파일 읽어들임
		fread((uint8_t*)inputIMGBf[i], sizeof(uint8_t), IMG_WIDTH, fpinput);
	}

	//이미지 변환 단계 코드 (미완성)


	/*메모리 할당 해제*/
	memory_free2D(inputIMGBf); 
	/*파일 닫기*/
	fclose(fpinput);
	fclose(fpoutput);

	return 0;
}