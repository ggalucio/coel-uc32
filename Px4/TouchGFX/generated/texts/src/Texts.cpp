/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) //Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x50, 0x61, 0x73, 0x73, 0x6f, 0x20, 0x61, 0x20, 0x70, 0x61, 0x73, 0x73, 0x6f, 0x20, 0x72, 0x65, 0x73, 0x65, 0x74, 0x20, 0x64, 0x65, 0x20, 0x66, 0xe1, 0x62, 0x72, 0x69, 0x63, 0x61, 0x3a, 0xa, 0xa, 0x31, 0x29, 0x20, 0x41, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x65, 0x20, 0x73, 0x65, 0x67, 0x75, 0x72, 0x65, 0x20, 0x6f, 0x20, 0x50, 0x20, 0x70, 0x6f, 0x72, 0x20, 0x73, 0x65, 0x67, 0x2e, 0xa, 0x32, 0x29, 0x20, 0x51, 0x75, 0x61, 0x6e, 0x64, 0x6f, 0x20, 0x61, 0x70, 0x61, 0x72, 0x65, 0x63, 0x65, 0x72, 0x20, 0x72, 0x50, 0x20, 0x61, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x50, 0x20, 0x75, 0x6d, 0x61, 0x20, 0x76, 0x65, 0x7a, 0xa, 0x33, 0x29, 0x20, 0x49, 0x6e, 0x73, 0x69, 0x72, 0x61, 0x20, 0x61, 0x20, 0x73, 0x65, 0x6e, 0x68, 0x61, 0x20, 0x2d, 0x34, 0x38, 0x20, 0x65, 0x20, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x65, 0x20, 0x63, 0x6f, 0x6d, 0x20, 0x50, 0xa, 0x34, 0x29, 0x20, 0x45, 0x73, 0x70, 0x65, 0x72, 0x65, 0x20, 0x6f, 0x20, 0x58, 0x33, 0x34, 0x20, 0x72, 0x65, 0x69, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x72, 0xa, 0x35, 0x29, 0x20, 0x41, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x6f, 0x20, 0x62, 0x6f, 0x74, 0xe3, 0x6f, 0x20, 0x61, 0x62, 0x61, 0x69, 0x78, 0x6f, 0x0, // @0 "Passo a passo reset de f?brica:??1) Aperte e segure o P por seg.?2) Quando aparecer rP aperte P uma vez?3) Insira a senha -48 e confirme com P?4) Espere o X34 reiniciar?5) Aperte o bot?o abaixo"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x32, 0x20, 0x2d, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0xa, 0x30, 0x20, 0x3d, 0x20, 0x64, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x64, 0x6f, 0xa, 0x31, 0x20, 0x3d, 0x20, 0x22, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x22, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x61, 0x74, 0x6f, 0x20, 0x3e, 0x20, 0x61, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0xa, 0x2d, 0x31, 0x20, 0x3d, 0x20, 0x22, 0x69, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x69, 0x64, 0x6f, 0x22, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x65, 0x72, 0x74, 0x6f, 0x20, 0x3e, 0x20, 0x61, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x0, // @194 "Logica entrada Digital 2 - Alarme Externo?0 = desabilitado?1 = "normal" = contato > alarme?-1 = "invertido" = aberto > alarme"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x31, 0xa, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x6f, 0x20, 0x73, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x20, 0x64, 0x65, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0x20, 0x28, 0x31, 0x20, 0x3d, 0x20, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x20, 0x2f, 0x20, 0x2d, 0x31, 0x20, 0x3d, 0x20, 0x69, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x69, 0x64, 0x6f, 0x29, 0x0, // @320 "Logica entrada Digital 1?Status do sensor de porta (1 = normal / -1 = invertido)"
    0x50, 0x4f, 0x52, 0x43, 0x45, 0x4e, 0x54, 0x41, 0x47, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0xa, 0x46, 0x31, 0x20, 0x3e, 0x20, 0x46, 0x32, 0xa, 0x28, 0x45, 0x78, 0x2e, 0x20, 0x36, 0x20, 0x3d, 0x20, 0x36, 0x30, 0x25, 0x20, 0x46, 0x31, 0x20, 0x2f, 0x20, 0x34, 0x30, 0x25, 0x20, 0x46, 0x32, 0x29, 0x0, // @401 "PORCENTAG RESFRIAR TEMP - HARD?F1 > F2?(Ex. 6 = 60% F1 / 40% F2)"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x32, 0x20, 0x2d, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0xa, 0x30, 0x20, 0x3d, 0x20, 0x64, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x64, 0x6f, 0x0, // @466 "Logica entrada Digital 2 - Alarme Externo?0 = desabilitado"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x74, 0x6f, 0x72, 0x6e, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0xa, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x29, 0x20, 0x2d, 0x20, 0x6d, 0xe1, 0x78, 0x20, 0x33, 0x30, 0x20, 0x6d, 0x69, 0x6e, 0x2e, 0x0, // @525 "Tempo de Retorno do Alarme?Externo (min.) - m?x 30 min."
    0x52, 0x65, 0x74, 0x61, 0x72, 0x64, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x76, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x61, 0x70, 0xf3, 0x73, 0xa, 0x74, 0xe9, 0x6d, 0x69, 0x6e, 0x69, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x73, 0x65, 0x67, 0x29, 0x0, // @581 "Retardo do ventilador ap?s?t?minio do degelo (min.seg)"
    0x45, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x34, 0x20, 0x28, 0x4f, 0x4e, 0x2f, 0x4f, 0x46, 0x46, 0x29, 0xa, 0x54, 0x65, 0x63, 0x6c, 0x61, 0x20, 0x52, 0x65, 0x64, 0x69, 0x61, 0x6c, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x0, // @636 "Entrada Digital 4 (ON/OFF)?Tecla Redial de Receita"
    0x56, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x6c, 0x69, 0x67, 0x61, 0x64, 0x6f, 0x20, 0x6e, 0x6f, 0x20, 0x44, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x3f, 0xa, 0x28, 0x30, 0x20, 0x3d, 0x20, 0x4e, 0xe3, 0x6f, 0x20, 0x2f, 0x20, 0x31, 0x20, 0x3d, 0x20, 0x53, 0x69, 0x6d, 0x29, 0x0, // @687 "Ventilador ligado no Degelo ??(0 = N?o / 1 = Sim)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x32, 0x20, 0x2f, 0x20, 0x53, 0x4f, 0x46, 0x54, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @737 "SP RESFRIAR SONDA - HARD F2 / SOFT?(SONDA ESPETO)"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x53, 0x75, 0x70, 0x65, 0x72, 0x69, 0x6f, 0x72, 0xa, 0x62, 0x6c, 0x6f, 0x71, 0x75, 0x65, 0x69, 0x6f, 0x20, 0x76, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @787 "Temperatura Superior?bloqueio ventilador (?C)"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x68, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @833 "Temperatura evaporador?habilitar de gelo (?C)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x32, 0x20, 0x2f, 0x20, 0x53, 0x4f, 0x46, 0x54, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @879 "SP RESFRIAR - HARD F2 / SOFT?(SONDA AMBIENTE)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x2d, 0x48, 0x41, 0x4e, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @925 "SP RESFRIAR SONDA -HAND F1?(SONDA ESPETO)"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x20, 0x75, 0x6c, 0x74, 0x69, 0x6d, 0x6f, 0x20, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x6f, 0xa, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x61, 0x74, 0x69, 0x63, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x65, 0x3f, 0x0, // @967 "Inicia ultimo processo?automaticamente?"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x66, 0x69, 0x6d, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @1007 "Temperatura evaporador?fim de gelo (?C)"
    0x50, 0x4f, 0x52, 0x43, 0x45, 0x4e, 0x54, 0x41, 0x47, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0xa, 0x46, 0x31, 0x20, 0x3e, 0x20, 0x46, 0x32, 0x0, // @1047 "PORCENTAG RESFRIAR TEMP - HARD?F1 > F2"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1086 "SP RESFRIAR - HARD F1?(SONDA AMBIENTE)"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x29, 0x0, // @1125 "Status da porta?para entrar no degelo)"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @1164 "Status da porta?para entrar no degelo"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1202 "SP CONGELAR TEMPO?(SONDA AMBIENTE)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1237 "SP CONGELAR SONDA?(SONDA AMBIENTE)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @1272 "SP CONGELAR SONDA?(SONDA ESPETO)"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x2f, 0x53, 0x4f, 0x46, 0x54, 0x0, // @1305 "DIFERENCIAL RESFRIAR - HARD/SOFT"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x67, 0x6f, 0x74, 0x65, 0x6a, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x6f, 0xa, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x73, 0x65, 0x64, 0x29, 0x0, // @1338 "Tempo de gotejamento?(min.sed)"
    0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x2e, 0xa, 0x61, 0x70, 0xf3, 0x73, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @1369 "Conservar autom.?ap?s receita:"
    0x52, 0x65, 0x74, 0x61, 0x72, 0x64, 0x6f, 0x20, 0x73, 0x61, 0xed, 0x64, 0x61, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x65, 0xa, 0x28, 0x6d, 0x6d, 0x2e, 0x73, 0x73, 0x29, 0x0, // @1400 "Retardo sa?da controle?(mm.ss)"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x67, 0x65, 0x6c, 0x61, 0x72, 0x29, 0x0, // @1431 "Dif. Conservar (Congelar)"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x69, 0x61, 0x72, 0x29, 0x0, // @1457 "Dif. Conservar (Resfriar)"
    0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x0, // @1483 "Descri??o Alarme Externo"
    0x44, 0x75, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x29, 0x0, // @1508 "Dura??o do degelo (min.)"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x72, 0x65, 0x63, 0x69, 0x74, 0x61, 0x20, 0x65, 0x6d, 0x20, 0x5a, 0x45, 0x52, 0x4f, 0x21, 0x0, // @1533 "Tempo de recita em ZERO!"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x29, 0x0, // @1558 "SP CONSERVA??O (Config.)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x2e, 0x29, 0x0, // @1583 "SP CONSERVA??O (Resfr.)"
    0x43, 0x4f, 0x4e, 0x54, 0x52, 0x41, 0x53, 0x45, 0x4e, 0x41, 0x20, 0x49, 0x4e, 0x43, 0x4f, 0x52, 0x52, 0x45, 0x43, 0x54, 0x41, 0x0, // @1607 "CONTRASENA INCORRECTA"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x0, // @1629 "ABCDEFGHIJKLMNOPQRST"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x0, // @1650 "DIFERENCIAL CONGELAR"
    0x4d, 0x41, 0x55, 0x56, 0x41, 0x49, 0x53, 0x20, 0x4d, 0x4f, 0x54, 0x20, 0x44, 0x45, 0x20, 0x50, 0x41, 0x53, 0x53, 0x45, 0x0, // @1671 "MAUVAIS MOT DE PASSE"
    0x45, 0x64, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x20, 0x31, 0x0, // @1692 "Edi??o de Receita 1"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x31, 0x0, // @1712 "Calibra??o Sonda 1"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x32, 0x0, // @1731 "Calibra??o Sonda 2"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x33, 0x0, // @1750 "Calibra??o Sonda 3"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0x20, 0x45, 0x56, 0x41, 0x50, 0x4f, 0x52, 0x41, 0x44, 0x4f, 0x52, 0x0, // @1769 "TEMP. EVAPORADOR"
    0x53, 0x65, 0x6e, 0x68, 0x61, 0x20, 0x64, 0x65, 0x20, 0x61, 0x63, 0x65, 0x73, 0x73, 0x6f, 0x0, // @1786 "Senha de acesso"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x39, 0x2d, 0x52, 0x31, 0x32, 0x0, // @1802 "RECEITAS R9-R12"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1818 "TEMPO?DECORRIDO"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @1834 "ABCDEFGHIIJKLMN"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x72, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x0, // @1850 "Iniciar Receita"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0x20, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1866 "TEMPO DECORRIDO"
    0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x20, 0x2, 0x0, // @1882 "Receita <>"
    0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x20, 0x45, 0x52, 0x52, 0x41, 0x54, 0x41, 0x0, // @1892 "PASSWORD ERRATA"
    0x4c, 0x49, 0x4d, 0x49, 0x54, 0x49, 0x20, 0x53, 0x55, 0x50, 0x45, 0x52, 0x41, 0x54, 0x49, 0x0, // @1908 "LIMITI SUPERATI"
    0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x21, 0x0, // @1924 "Alarme Externo!"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @1940 "ABCDEFGHIJKLMN"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x45, 0x53, 0x54, 0x49, 0x4d, 0x41, 0x44, 0x4f, 0x0, // @1955 "TEMPO?ESTIMADO"
    0x48, 0x4f, 0x52, 0x53, 0x20, 0x44, 0x45, 0x20, 0x50, 0x4f, 0x52, 0x54, 0xc9, 0x45, 0x0, // @1970 "HORS DE PORT?E"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x35, 0x2d, 0x52, 0x38, 0x0, // @1985 "RECEITAS R5-R8"
    0x46, 0x55, 0x45, 0x52, 0x41, 0x20, 0x44, 0x45, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x4f, 0x0, // @2000 "FUERA DE RANGO"
    0x57, 0x52, 0x4f, 0x4e, 0x47, 0x20, 0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x0, // @2015 "WRONG PASSWORD"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x31, 0x2d, 0x52, 0x34, 0x0, // @2030 "RECEITAS R1-R4"
    0x54, 0x69, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @2045 "Tipo de degelo"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x43, 0x4f, 0x4e, 0x46, 0x49, 0x47, 0x2e, 0x0, // @2060 "TEMPO?CONFIG."
    0x41, 0x42, 0x52, 0x49, 0x52, 0x20, 0x50, 0x4f, 0x52, 0x54, 0x41, 0x20, 0x21, 0x0, // @2074 "ABRIR PORTA !"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x20, 0x46, 0xe1, 0x62, 0x72, 0x69, 0x63, 0x61, 0x0, // @2088 "Reset F?brica"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x50, 0x52, 0x4f, 0x44, 0x55, 0x54, 0x4f, 0x0, // @2102 "TEMP.?PRODUTO"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x4e, 0x41, 0x0, // @2116 "TEMP.?INTERNA"
    0x53, 0x6f, 0x6d, 0x20, 0x64, 0x6f, 0x20, 0x42, 0x75, 0x7a, 0x7a, 0x65, 0x72, 0x0, // @2130 "Som do Buzzer"
    0x44, 0x65, 0x73, 0x61, 0x62, 0x6c, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x0, // @2144 "Desablilitar"
    0x4f, 0x55, 0x54, 0x20, 0x4f, 0x46, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @2157 "OUT OF RANGE"
    0x4d, 0x6f, 0x64, 0x6f, 0x3a, 0xa, 0x66, 0x75, 0x6e, 0x63, 0x2e, 0x0, // @2170 "Modo:?func."
    0x4f, 0x50, 0x45, 0x52, 0x41, 0x4e, 0x44, 0x4f, 0x2e, 0x2e, 0x2e, 0x0, // @2182 "OPERANDO..."
    0x46, 0x69, 0x6e, 0x61, 0x6c, 0x69, 0x7a, 0x61, 0x64, 0x6f, 0x21, 0x0, // @2194 "Finalizado!"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x0, // @2206 "Temperatura"
    0x4d, 0x6f, 0x64, 0x6f, 0xa, 0x66, 0x69, 0x6e, 0x61, 0x6c, 0x2e, 0x0, // @2218 "Modo?final."
    0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0x52, 0x0, // @2230 "CONSERVAR"
    0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x0, // @2240 "RESFRIAR"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @2249 "New Text"
    0x43, 0x41, 0x4e, 0x43, 0x45, 0x4c, 0x41, 0x52, 0x0, // @2258 "CANCELAR"
    0x49, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x65, 0x72, 0x0, // @2267 "Inverter"
    0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @2276 "Receita:"
    0x2, 0x2e, 0x0, // @2285 "<>."
    0x49, 0x4e, 0x44, 0x49, 0x45, 0x54, 0x52, 0x4f, 0x0, // @2288 "INDIETRO"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0xa, 0x0, // @2297 "Enter??"
    0x38, 0x38, 0x38, 0x38, 0x2e, 0x38, 0x0, // @2305 "8888.8"
    0x4e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x0, // @2312 "Normal"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0x0, // @2319 "Enter?"
    0x32, 0x30, 0x30, 0x30, 0x2e, 0x30, 0x0, // @2326 "2000.0"
    0x53, 0x41, 0x4c, 0x56, 0x41, 0x52, 0x0, // @2333 "SALVAR"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x0, // @2340 "Cancel"
    0x44, 0x45, 0x47, 0x45, 0x4c, 0x4f, 0x0, // @2347 "DEGELO"
    0x45, 0x4e, 0x54, 0x45, 0x52, 0x0, // @2354 "ENTER"
    0x43, 0x4c, 0x45, 0x41, 0x52, 0x0, // @2360 "CLEAR"
    0x38, 0x38, 0x38, 0x38, 0x38, 0x0, // @2366 "88888"
    0x41, 0x54, 0x52, 0xc1, 0x53, 0x0, // @2372 "ATR?S"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x0, // @2378 "Reset"
    0x38, 0x38, 0x2e, 0x38, 0x38, 0x0, // @2384 "88.88"
    0x4e, 0x6f, 0x6d, 0x65, 0x3a, 0x0, // @2390 "Nome:"
    0x43, 0x61, 0x70, 0x73, 0xa, 0x0, // @2396 "Caps?"
    0x43, 0x70, 0x61, 0x73, 0xa, 0x0, // @2402 "Cpas?"
    0x44, 0x65, 0x6c, 0xa, 0xa, 0x0, // @2408 "Del??"
    0x4d, 0x69, 0x6e, 0x2e, 0x0, // @2414 "Min."
    0x42, 0x41, 0x43, 0x4b, 0x0, // @2419 "BACK"
    0x43, 0x6f, 0x65, 0x6c, 0x0, // @2424 "Coel"
    0x44, 0x65, 0x6c, 0xa, 0x0, // @2429 "Del?"
    0x45, 0x73, 0x63, 0xa, 0x0, // @2434 "Esc?"
    0x31, 0x32, 0x33, 0xa, 0x0, // @2439 "123?"
    0x4d, 0x69, 0x6e, 0x0, // @2444 "Min"
    0x4d, 0x61, 0x78, 0x0, // @2448 "Max"
    0x41, 0x42, 0x43, 0x0, // @2452 "ABC"
    0x31, 0x32, 0x33, 0x0, // @2456 "123"
    0x6d, 0x69, 0x6e, 0x0, // @2460 "min"
    0x4e, 0xc3, 0x4f, 0x0, // @2464 "N?O"
    0x53, 0x49, 0x4d, 0x0, // @2468 "SIM"
    0x2b, 0x2f, 0x2d, 0x0, // @2472 "+/-"
    0x45, 0x53, 0x43, 0x0, // @2476 "ESC"
    0x44, 0x4f, 0x53, 0x0, // @2480 "DOS"
    0xb0, 0x43, 0x0, // @2484 "?C"
    0x30, 0x30, 0x0, // @2487 "00"
    0x4f, 0x6b, 0x0, // @2490 "Ok"
    0x2d, 0x2d, 0x0, // @2493 "--"
    0x20, 0x0, // @2496 " "
    0x35, 0x0, // @2498 "5"
    0x36, 0x0, // @2500 "6"
    0x2f, 0x0, // @2502 "/"
    0x37, 0x0, // @2504 "7"
    0x39, 0x0, // @2506 "9"
    0x27, 0x0, // @2508 "'"
    0x22, 0x0, // @2510 """
    0x28, 0x0, // @2512 "("
    0x2b, 0x0, // @2514 "+"
    0x5f, 0x0, // @2516 "_"
    0x2a, 0x0, // @2518 "*"
    0x26, 0x0, // @2520 "&"
    0x25, 0x0, // @2522 "%"
    0x24, 0x0, // @2524 "$"
    0x23, 0x0, // @2526 "#"
    0x40, 0x0, // @2528 "@"
    0x3b, 0x0, // @2530 ";"
    0x2c, 0x0, // @2532 ","
    0x73, 0x0, // @2534 "s"
    0x6d, 0x0, // @2536 "m"
    0x62, 0x0, // @2538 "b"
    0x42, 0x0, // @2540 "B"
    0x76, 0x0, // @2542 "v"
    0x56, 0x0, // @2544 "V"
    0x63, 0x0, // @2546 "c"
    0x58, 0x0, // @2548 "X"
    0x7a, 0x0, // @2550 "z"
    0x5a, 0x0, // @2552 "Z"
    0x4c, 0x0, // @2554 "L"
    0x6a, 0x0, // @2556 "j"
    0x4a, 0x0, // @2558 "J"
    0x68, 0x0, // @2560 "h"
    0x48, 0x0, // @2562 "H"
    0x67, 0x0, // @2564 "g"
    0x47, 0x0, // @2566 "G"
    0x66, 0x0, // @2568 "f"
    0x46, 0x0, // @2570 "F"
    0x64, 0x0, // @2572 "d"
    0x70, 0x0, // @2574 "p"
    0x50, 0x0, // @2576 "P"
    0x69, 0x0, // @2578 "i"
    0x75, 0x0, // @2580 "u"
    0x55, 0x0, // @2582 "U"
    0x79, 0x0, // @2584 "y"
    0x59, 0x0, // @2586 "Y"
    0x77, 0x0, // @2588 "w"
    0x71, 0x0, // @2590 "q"
    0x57, 0x0, // @2592 "W"
    0x51, 0x0 // @2594 "Q"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesIt[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesEs[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesFr[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[4] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb,
    indicesIt,
    indicesEs,
    indicesFr
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 4)
    {
        if (languagesArray[id] != 0)
        {
            //dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            //compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
