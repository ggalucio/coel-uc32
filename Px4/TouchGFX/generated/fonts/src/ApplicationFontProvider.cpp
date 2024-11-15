/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::DEFAULT:
        // verdana_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::LARGE:
        // verdana_40_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::SMALL:
        // verdanab_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::VERDANA15:
        // verdana_15_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    case Typography::VERDANA30:
        // verdana_30_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[4]);
    case Typography::VERDANA25:
        // verdana_25_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[5]);
    case Typography::KEYBOARD:
        // arial_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[6]);
    case Typography::DISPLAY:
        // arial_28_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[7]);
    case Typography::MODE:
        // arial_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[8]);
    case Typography::VERDANA18:
        // verdana_18_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[9]);
    case Typography::VERDANA28_BOLD:
        // verdanab_28_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[10]);
    case Typography::VERDANA_20_BOLD:
        // verdanab_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[11]);
    case Typography::VERDANA_28:
        // verdana_28_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[12]);
    case Typography::VERDANA_15_BOLD:
        // verdanab_15_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[13]);
    case Typography::DISPLAY_60:
        // arial_60_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[14]);
    case Typography::DIGITAL7_72_ITALIC:
        // digital7italic_72_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[15]);
    case Typography::DIGITAL7_36_ITALIC:
        // digital7italic_36_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[16]);
    case Typography::DIGITAL7_18_ITALIC:
        // digital7italic_18_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[17]);
    case Typography::DIGITAL7_22_ITALIC:
        // digital7italic_22_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[18]);
    case Typography::DIGITAL7_28_ITALIC:
        // digital7italic_28_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[19]);
    case Typography::ARIAL_72:
        // arial_72_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[20]);
    case Typography::VEDANA_10:
        // verdana_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[21]);
    case Typography::VERDANA_20_ITAIC:
        // verdanai_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[22]);
    case Typography::SEGOEUI30:
        // segoeui_30_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[23]);
    default:
        return 0;
    }
}
