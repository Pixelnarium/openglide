//**************************************************************
//*            OpenGLide - Glide to OpenGL Wrapper
//*             http://openglide.sourceforge.net
//*
//*                     Other Functions
//*
//*         OpenGLide is OpenSource under LGPL license
//*              Originaly made by Fabio Barros
//*      Modified by Paul for Glidos (http://www.glidos.net)
//**************************************************************

#include "GlOgl.h"


// Error Function variable
extern void (*ExternErrorFunction)(const char *string, FxBool fatal);


//*************************************************
//* Sets the External Error Function to call if
//* Glides Generates and Error
//*************************************************
DLLEXPORT void __stdcall
grErrorSetCallback( void (*function)(const char *string, FxBool fatal) )
{
#ifdef DONE
    GlideMsg( "grErrorSetCallback( --- )\n" );
#endif

    ExternErrorFunction = function;
}

//*************************************************
//* Sets the Cull Mode
//*************************************************
DLLEXPORT void __stdcall
grCullMode( GrCullMode_t mode )
{
#ifdef DONE
    GlideMsg( "grCullMode( %d )\n", mode );
#endif

    RenderDrawTriangles( );

    Glide.State.CullMode = mode;

    switch ( Glide.State.CullMode )
    {
    case GR_CULL_DISABLE:
        glDisable( GL_CULL_FACE );
        glCullFace( GL_BACK );  // This will be called in initialization
        break;

    case GR_CULL_NEGATIVE:
        glEnable( GL_CULL_FACE );
        if ( Glide.State.OriginInformation == GR_ORIGIN_LOWER_LEFT )
        {
            glFrontFace( GL_CCW );
        }
        else
        {
            glFrontFace( GL_CW );
        }
        break;

    case GR_CULL_POSITIVE:
        glEnable( GL_CULL_FACE );
        if ( Glide.State.OriginInformation == GR_ORIGIN_LOWER_LEFT )
        {
            glFrontFace( GL_CW );
        }
        else
        {
            glFrontFace( GL_CCW );
        }
        break;
    }

#ifdef OPENGL_DEBUG
    GLErro( "grCullMode" );
#endif
}

//*************************************************
//* Set the size and location of the hardware clipping window
//*************************************************
DLLEXPORT void __stdcall 
grClipWindow( FxU32 minx, FxU32 miny, FxU32 maxx, FxU32 maxy )
{
#ifdef PARTDONE
    GlideMsg("grClipWindow( %d, %d, %d, %d )\n", minx, miny, maxx, maxy );
#endif

    RenderDrawTriangles( );

    Glide.State.ClipMinX = minx;
    Glide.State.ClipMaxX = maxx;
    Glide.State.ClipMinY = miny;
    Glide.State.ClipMaxY = maxy;
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall 
grDisableAllEffects( void )
{
#ifdef PARTDONE
    GlideMsg("grDisableAllEffects()\n");
#endif

    grAlphaBlendFunction( GR_BLEND_ONE, GR_BLEND_ZERO, GR_BLEND_ONE, GR_BLEND_ZERO );
    grAlphaTestFunction( GR_CMP_ALWAYS );
    grChromakeyMode( GR_CHROMAKEY_DISABLE );
    grDepthBufferMode( GR_DEPTHBUFFER_DISABLE );
    grFogMode( GR_FOG_DISABLE );
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall
grResetTriStats( void )
{
#ifdef NOTDONE
    GlideMsg("grResetTriStats\n");
#endif
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall
grTriStats( FxU32 *trisProcessed, FxU32 *trisDrawn )
{
#ifdef NOTDONE
    GlideMsg("grTriStats\n");
#endif
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall
grHints( GrHint_t hintType, FxU32 hintMask )
{
#ifdef PARTDONE
    GlideMsg("grHints( %d, %d )\n", hintType, hintMask );
#endif

    switch( hintType )
    {
    case GR_HINT_STWHINT:
        Glide.State.STWHint = hintMask;
        break;
    }
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall
grSplash( float x, float y, float width, float height, FxU32 frame )
{
#ifdef NOTDONE
    GlideMsg("grSplash( %-4.2f, %-4.2f, %-4.2f, %-4.2f, %lu )\n",
        x, y, width, height, frame );
#endif
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall 
ConvertAndDownloadRle( GrChipID_t        tmu,
                       FxU32             startAddress,
                       GrLOD_t           thisLod,
                       GrLOD_t           largeLod,
                       GrAspectRatio_t   aspectRatio,
                       GrTextureFormat_t format,
                       FxU32             evenOdd,
                       FxU8              *bm_data,
                       long              bm_h,
                       FxU32             u0,
                       FxU32             v0,
                       FxU32             width,
                       FxU32             height,
                       FxU32             dest_width,
                       FxU32             dest_height,
                       FxU16             *tlut )
{
#ifdef NOTDONE
    GlideMsg( "ConvertAndDownloadRle( %d, %lu, %d, %d, %d, %d, %d, ---, %l, %lu, %lu, %lu, %lu, %lu, %lu, --- )\n",
        tmu, startAddress, thisLod, largeLod, aspectRatio, format, evenOdd, bm_h, u0, v0, width, height,
        dest_width, dest_height );
#endif
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall 
grCheckForRoom( FxI32 n )
{
#ifdef NOTDONE
    GlideMsg( "grCheckForRoom( %l )\n", n );
#endif
}

//----------------------------------------------------------------
DLLEXPORT void __stdcall
grParameterData( FxU32 param, FxU32 components, FxU32 type, FxI32 offset )
{
#ifdef NOTDONE
    GlideMsg( "grParameterData( %lu, %lu, %lu, %l )\n",
        param, components, type, offset );
#endif
}

//----------------------------------------------------------------
DLLEXPORT int __stdcall
guEncodeRLE16( void *dst, 
               void *src, 
               FxU32 width, 
               FxU32 height )
{
#ifdef NOTDONE
    GlideMsg("guEncodeRLE16( ---, ---, %lu, %lu )\n", width, height ); 
#endif

    return 1; 
}

//----------------------------------------------------------------
DLLEXPORT FxU32 __stdcall
guEndianSwapWords( FxU32 value )
{
#ifdef PARTDONE
    GlideMsg( "guEndianSwapWords( %lu )\n", value );
#endif

    return ( value << 16 ) | ( value >> 16 );
}

//----------------------------------------------------------------
DLLEXPORT FxU16 __stdcall
guEndianSwapBytes( FxU16 value )
{
#ifdef PARTDONE
    GlideMsg( "guEndianSwapBytes( %u )\n", value );
#endif
    return ( value << 8 ) | ( value >> 8 );
}
