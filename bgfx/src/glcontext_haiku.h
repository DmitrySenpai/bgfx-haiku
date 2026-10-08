#ifndef BGFX_GLCONTEXT_HAIKU_H_HEADER_GUARD
#define BGFX_GLCONTEXT_HAIKU_H_HEADER_GUARD

#if BGFX_USE_HAIKU

class BGLView;

namespace bgfx { namespace gl
{

struct SwapChainGL
{
};

struct GlContext
{
    GlContext()
        : m_view(NULL)
        , m_locked(false)
        , m_vsync(false)
        , m_msaaContext(false)
    {
    }

    void create(uint32_t _width, uint32_t _height, uint32_t _flags);
    void destroy();
    void resize(uint32_t _width, uint32_t _height, uint32_t _flags);

    uint64_t getCaps() const;

    SwapChainGL* createSwapChain(
        void* _nwh,
        int32_t _width,
        int32_t _height
    );

    void destroySwapChain(SwapChainGL* _swapChain);

    void swap(SwapChainGL* _swapChain = NULL);
    void makeCurrent(SwapChainGL* _swapChain = NULL);

    void import();

    bool isValid() const
    {
        return NULL != m_view;
    }

    ::BGLView* m_view;
    bool m_locked;
    bool m_vsync;

    // This Haiku backend wraps an SDL-created BGLView.
    // MSAA, when needed, is handled by bgfx through an FBO.
    bool m_msaaContext;
};

} } // namespace bgfx::gl

#endif // BGFX_USE_HAIKU

#endif
