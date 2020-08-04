#pragma once

constexpr uint8_t mainScreenBitmapWidth = 128;
constexpr uint8_t mainScreenBitmapHeight = 64;

const uint8_t PROGMEM mainScreenBitmap[] =
{
  //mainScreenBitmapWidth, mainScreenBitmapHeight,
  //Frame 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0x9C, 0x8E, 0x87, 0x83, 0x87, 0x8E, 0x9C, 0xF8, 0xF0, 0x00, 0x00, 0xFE, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0xFE, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFF, 0x83, 0x83, 0x83, 0x83, 0x83, 0xC7, 0xEE, 0x7C, 0x38, 0x00, 0x00, 0xF8, 0xFC, 0x0E, 0x07, 0x03, 0x03, 0x03, 0x07, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0x3F, 0x7F, 0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xE0, 0x7F, 0x3F, 0x00, 0x00, 0x18, 0xDC, 0xFC, 0xFC, 0xFE, 0xDE, 0xCE, 0xC7, 0x47, 0x67, 0x63, 0x7B, 0xBB, 0xF3, 0xE0, 0xE0, 0xE0, 0xF0, 0x78, 0x3C, 0x3E, 0x1E, 0x0F, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x3E, 0x77, 0xE3, 0xC1, 0x00, 0x00, 0x7F, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x70, 0x3F, 0x1F, 0x00, 0x00, 0x1F, 0x3F, 0x70, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0x70, 0x3F, 0x1F, 0x00, 0x00, 0x7F, 0xFF, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xE3, 0x77, 0x3E, 0x1C, 0x00, 0x00, 0x1F, 0x3F, 0x70, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0x70, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1F, 0x07, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x04, 0x06, 0x06, 0x07, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0xA8, 0x04, 0xC8, 0xE4, 0x28, 0x24, 0xE8, 0xC4, 0x08, 0xC4, 0xE8, 0x24, 0x28, 0x64, 0x48, 0x04, 0x28, 0x24, 0xE8, 0xE4, 0x28, 0x24, 0x08, 0xE4, 0xE8, 0x04, 0xE8, 0xE4, 0x08, 0x04, 0xE8, 0xE4, 0x08, 0xC4, 0xE8, 0x24, 0x28, 0xE4, 0xC8, 0x04, 0x28, 0x24, 0xE8, 0xE4, 0x28, 0x24, 0x08, 0xC4, 0xE8, 0x24, 0x28, 0xE4, 0xC8, 0x04, 0xE8, 0xE4, 0x28, 0x24, 0xE8, 0xC4, 0x08, 0x04, 0xA8, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x2A, 0x40, 0x2F, 0x4F, 0x23, 0x43, 0x2F, 0x4F, 0x20, 0x47, 0x2F, 0x48, 0x28, 0x4C, 0x24, 0x40, 0x20, 0x40, 0x2F, 0x4F, 0x20, 0x40, 0x20, 0x4F, 0x2F, 0x40, 0x23, 0x47, 0x2C, 0x4C, 0x27, 0x43, 0x20, 0x4F, 0x2F, 0x42, 0x22, 0x4F, 0x2F, 0x40, 0x20, 0x40, 0x2F, 0x4F, 0x20, 0x40, 0x20, 0x47, 0x2F, 0x48, 0x28, 0x4F, 0x27, 0x40, 0x2F, 0x4F, 0x22, 0x42, 0x2F, 0x4D, 0x20, 0x40, 0x2A, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x50, 0xD0, 0x00, 0x10, 0xF0, 0x10, 0x00, 0xF0, 0x50, 0xF0, 0x00, 0x10, 0xF0, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x70, 0x50, 0xD0, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x30, 0x60, 0x30, 0xF8, 0x00, 0xF0, 0x08, 0x08, 0x08, 0xF0, 0x01, 0xF9, 0x09, 0x08, 0xF0, 0x01, 0x00, 0x00, 0xF1, 0x08, 0x09, 0x10, 0x00, 0xF9, 0x40, 0x40, 0xF9, 0x01, 0x09, 0xF8, 0x09, 0x01, 0xF9, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x40, 0xC0, 0x40, 0xC0, 0x00, 0xC0, 0x40, 0x40, 0x00, 0xC0, 0x80, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x03, 0xE0, 0x00, 0x00, 0x03, 0x00, 0xC1, 0x22, 0x22, 0xC2, 0x01, 0xC0, 0x23, 0x22, 0x42, 0x01, 0xE0, 0x00, 0x00, 0xE1, 0x02, 0x02, 0x01, 0xC0, 0x23, 0x20, 0x40, 0x03, 0xE0, 0x02, 0x03, 0xE2, 0x00, 0x23, 0xE0, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x07, 0x80, 0x47, 0x45, 0xA4, 0xA0, 0xA7, 0x40, 0x41, 0x87, 0x00, 0x07, 0x04, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x07, 0x08, 0x08, 0x04, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x08, 0x0F, 0x08, 0x00, 0x0F, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x3F, 0x7F, 0x47, 0xE9, 0xEE, 0xE9, 0x47, 0x7F, 0x3F, 0x0E, 0x00, 0x00, 0x00
};

constexpr uint8_t checkBitmapWidth = 8;
constexpr uint8_t checkBitmapHeight = 8;

const uint8_t PROGMEM checkBitmap[] =
{
  //checkBitmapWidth, checkBitmapHeight,
  //Frame 0
  0x04, 0x0C, 0x38, 0x70, 0x3C, 0x0E, 0x03, 0x01
};

constexpr uint8_t crossBitmapWidth = 8;
constexpr uint8_t crossBitmapHeight = 8;

const uint8_t PROGMEM crossBitmap[] =
{
  //crossBitmapWidth, crossBitmapHeight,
  //Frame 0
  0x41, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x41
};


constexpr uint8_t menuScreenBitmapWidth = 128;
constexpr uint8_t menuScreenBitmapHeight = 64;

const uint8_t PROGMEM menuScreenBitmap[] =
{
  //menuScreenBitmapWidth, menuScreenBitmapHeight,
  //Frame 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x08, 0x08, 0xF0, 0x00, 0x08, 0xF8, 0x08, 0x00, 0xF0, 0x48, 0x48, 0xF0, 0x00, 0xF0, 0x08, 0x48, 0xD0, 0x00, 0xF8, 0x30, 0xC0, 0xF8, 0x00, 0xF0, 0x08, 0x08, 0xF0, 0x00, 0x30, 0x48, 0x48, 0x90, 0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0x08, 0xF8, 0x08, 0x00, 0xF0, 0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x00, 0xF8, 0x30, 0xC0, 0xF8, 0x00, 0xF8, 0x48, 0x48, 0x08, 0x00, 0xF0, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x42, 0x42, 0x41, 0x00, 0xC2, 0x03, 0x02, 0x00, 0x03, 0x80, 0x40, 0x43, 0x80, 0x01, 0x82, 0x42, 0x41, 0x80, 0x03, 0xC0, 0x00, 0x03, 0xC0, 0x01, 0x02, 0x02, 0x01, 0xC0, 0x81, 0x02, 0x82, 0xC1, 0x00, 0x80, 0x40, 0x43, 0x80, 0x00, 0xC0, 0x42, 0x43, 0x82, 0x00, 0x01, 0x02, 0x02, 0x81, 0x40, 0x40, 0x80, 0x00, 0xC2, 0x03, 0x02, 0xC0, 0x03, 0x40, 0xC0, 0x43, 0x00, 0xC3, 0x40, 0x40, 0x80, 0x00, 0x01, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x02, 0x02, 0x00, 0x00, 0x1F, 0x10, 0x10, 0x10, 0x00, 0x1F, 0x02, 0x02, 0x1F, 0x00, 0x09, 0x12, 0x12, 0x0C, 0x00, 0x1F, 0x02, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x01, 0x03, 0x01, 0x1F, 0x00, 0x0F, 0x10, 0x10, 0x0F, 0x00, 0x1F, 0x10, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x10, 0x10, 0x08, 0x00, 0x1F, 0x02, 0x02, 0x1F, 0x00, 0x10, 0x1F, 0x10, 0x00, 0x1F, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x12, 0x12, 0x02, 0x00, 0xFE, 0x80, 0x80, 0x80, 0x00, 0xFC, 0x12, 0x12, 0xFC, 0x00, 0x4C, 0x92, 0x92, 0x64, 0x00, 0xFE, 0x10, 0x10, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x92, 0x92, 0x6C, 0x00, 0x7C, 0x82, 0x82, 0x7C, 0x00, 0x7C, 0x82, 0x82, 0x7C, 0x00, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0xFE, 0x80, 0x80, 0x80, 0x00, 0x7C, 0x82, 0x82, 0x7C, 0x00, 0xFC, 0x22, 0x22, 0xFC, 0x00, 0xFE, 0x82, 0x82, 0x7C, 0x00, 0xFE, 0x92, 0x92, 0x82, 0x00, 0xFE, 0x22, 0x62, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x90, 0x90, 0x10, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x90, 0x90, 0xE0, 0x00, 0x60, 0x90, 0x90, 0x20, 0x00, 0xF0, 0x80, 0x80, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x10, 0x10, 0xE0, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xE8, 0xE8, 0xE8, 0x18, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x02, 0x04, 0x04, 0x03, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x01, 0x07, 0x00, 0x07, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xA8, 0x04, 0x00, 0x04, 0x00, 0x04, 0x88, 0x51, 0x23, 0x07, 0x8F, 0x07, 0x23, 0x51, 0x88, 0x04, 0x00, 0x04, 0x00, 0x04, 0xA8, 0x00, 0x00, 0xB8, 0xA8, 0xE8, 0x00, 0xF8, 0xA8, 0x88, 0x00, 0xF8, 0x80, 0x80, 0x00, 0xF8, 0xA8, 0x88, 0x00, 0xF8, 0x88, 0x88, 0x00, 0x08, 0xF8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xA8, 0xB8, 0xE0, 0x00, 0xF8, 0x48, 0xF8, 0x00, 0xF8, 0x88, 0x88, 0x00, 0xF8, 0x30, 0xC8, 0x00, 0x00, 0x70, 0xFC, 0xFA, 0x0A, 0xD5, 0xD5, 0xCD, 0x3A, 0xFA, 0xFC, 0x70, 
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x7C, 0xFE, 0xFF, 0xFD, 0xFB, 0xC6, 0x7C, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00
};

constexpr uint8_t selectBitmapWidth = 98;
constexpr uint8_t selectBitmapHeight = 16;

const uint8_t PROGMEM selectBitmap[] =
{
  //selectBitmapWidth, selectBitmapHeight,
  //Frame 0
  0xE0, 0xF8, 0xF4, 0x74, 0x9A, 0xEA, 0x9A, 0x74, 0xF4, 0xF8, 0xE0, 0x00, 0x00, 0x54, 0xAA, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0xAA, 0x54, 
  0x00, 0x03, 0x07, 0x04, 0x0E, 0x0E, 0x0E, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x05, 0x0A, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x0A, 0x05
};

constexpr uint8_t buttonBitmapWidth = 11;
constexpr uint8_t buttonBitmapHeight = 16;

const uint8_t PROGMEM buttonBitmap[] =
{
  //buttonBitmapWidth, buttonBitmapHeight,
  //Frame 0
  0x70, 0xFC, 0xFA, 0x3A, 0x4D, 0x75, 0x4D, 0x3A, 0xFA, 0xFC, 0x70, 
  0x00, 0x01, 0x03, 0x02, 0x07, 0x07, 0x07, 0x02, 0x03, 0x01, 0x00
};

constexpr uint8_t leftRightBitmapWidth = 46;
constexpr uint8_t leftRightBitmapHeight = 24;

const uint8_t PROGMEM leftRightBitmap[] =
{
  //leftRightBitmapWidth, leftRightBitmapHeight,
  //Frame 0
  0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x2A, 0x41, 0x80, 0x01, 0x80, 0x41, 0x2A, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3D, 0x1B, 0x8E, 0x44, 0x20, 0x11, 0x20, 0x44, 0x8E, 0x1F, 0x3F, 0x3E, 0x3E, 0x3E, 0x31, 0x1F, 0x00, 0x00, 0x17, 0x15, 0x1D, 0x00, 0x1F, 0x15, 0x11, 0x00, 0x1F, 0x10, 0x10, 0x00, 0x1F, 0x15, 0x11, 0x00, 0x1F, 0x11, 0x11, 0x00, 0x01, 0x1F, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x10, 0x00, 0x10, 0x00, 0x10, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

constexpr uint8_t backButtonBitmapWidth = 29;
constexpr uint8_t backButtonBitmapHeight = 16;

const uint8_t PROGMEM backButtonBitmap[] =
{
  //backButtonBitmapWidth, backButtonBitmapHeight,
  //Frame 0
  0xF8, 0xA8, 0xB8, 0xE0, 0x00, 0xF8, 0x48, 0xF8, 0x00, 0xF8, 0x88, 0x88, 0x00, 0xF8, 0x30, 0xC8, 0x00, 0x00, 0x70, 0xFC, 0xFA, 0x0A, 0xD5, 0xD5, 0xCD, 0x3A, 0xFA, 0xFC, 0x70, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00
};

