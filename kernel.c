void main() {

    
    char* video_memory = (char*) 0xb8000;

    // Pula duas linhas cada tem 80 chars
    video_memory += 160 * 2;


    *video_memory++ = 'L';

    // Atributo de formatação (cor padrão)
    *video_memory++ = 0x0F;  // Por exemplo, 0x0F representa a cor branca sobre fundo preto

    // Escreve mais caracteres na mesma linha
    *video_memory++ = 'U';
    *video_memory++ = 0x0F;

    *video_memory++ = 'A';
    *video_memory++ = 0x0F;

    *video_memory++ = 'M';
    *video_memory++ = 0x0F;

    *video_memory++ = 'O';
    *video_memory++ = 0x01;

    *video_memory++ = 'S';
    *video_memory++ = 0x01;



    video_memory += (80-6) * 2;

    // for (int i = 0; i < 79; ++i) {
    //     *video_memory++ = ' ';
    //     *video_memory++ = 0x0F;
    // }


}
