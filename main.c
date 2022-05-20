#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push)
#pragma pack(1)
typedef struct
{
    uint16_t bfType;        //Отметка для отличия формата от других (сигнатура формата). Может содержать единственное значение 0x4D42/0x424D (little-endian/big-endian).
    uint32_t bfSize;        //Размер файла в байтах.
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits; //Положение пиксельных данных относительно начала данной структуры (в байтах).
} BmpHeader;
#pragma pack(pop)

int main()
{
    printf("Hello\n");
    FILE *fd;
    fd = fopen("E:\\Buffer\\hamster.bmp", "rb");
    if (fd == NULL)
    {
        printf("File not open\n");
    }

    uint8_t number[32];

    BmpHeader h;
    fread(&number, sizeof(uint8_t), 14, fd);
    fread(&h, sizeof(uint8_t), 14, fd);

    printf("%X ", h.bfType);

    for(int i = 0; i < 14; i++)
        printf("%X ", number[i] );


    fclose(fd);

    return 0;
}
