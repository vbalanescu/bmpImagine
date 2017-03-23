#include<stdio.h>
#include<windows.h>

typedef struct RGB {
	unsigned char R;
	unsigned char g;
	unsigned char B;
}RGB;

int main() {

	FILE *f;
	BITMAPFILEHEADER bh;
	BITMAPINFOHEADER ih;
	RGBTRIPLE pixel;

	f = fopen("imag.bmp", 'w+');
	fclose(f);
	
	fread(&bh, sizeof(BITMAPFILEHEADER), 1, f);
	fread(&ih, sizeof(BITMAPINFOHEADER), 1, f);

	int i = 0;

	while (fread(&pixel, sizeof(RGBTRIPLE), 1, f)) {
	
		printf("pixel #%5d: %02x %02x %02x\n", i++,
			pixel.rgbtBlue, pixel.rgbtGreen, pixel.rgbtRed);
	}

	printf("%d pixels read.\n", i);

}