// ----------------------------------- framebf.h -------------------------------------
void framebf_init();
void drawPixelARGB32(int x, int y, unsigned int attr);
void drawRectARGB32(int x1, int y1, int x2, int y2, unsigned int attr, int fill);
void drawLineARGB32(int x1, int y1, int x2, int y2, unsigned int attr);
void drawCircleARGB32(int x, int y, int r, unsigned int attr);
void drawImage(int x, int y, unsigned long *imageData, int width, int height);
void drawImageWithOffset(int x, int y, unsigned long *imageData, int width, int height, int yOffset);
void clearFrameBuffer();
void waitMiliSeconds(unsigned int miliSeconds);
void drawCharWithColors(int x, int y, unsigned long *bitmap, int charHeight, int charWidth, unsigned int textColor, unsigned int bgColor);
void drawStr(int x, int y, unsigned long *str[], int charHeight, int charWidth, unsigned int textColor, unsigned int bgColor);
void drawScaledDown(int x, int y, const unsigned long* bitmap, short originalWidth, short originalHeight,unsigned long color, unsigned long bg, short scale);
void drawStrScaledDown(int x, int y, unsigned long *str[], int charHeight, int charWidth, unsigned int textColor, unsigned int bgColor, short scale);
