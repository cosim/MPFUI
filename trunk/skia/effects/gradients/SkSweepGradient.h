
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSweepGradient_DEFINED
#define SkSweepGradient_DEFINED

#include "SkGradientShaderPriv.h"

class SkSweepGradient : public SkGradientShaderBase {
public:
    SkSweepGradient(SkScalar cx, SkScalar cy, const Descriptor&);

    virtual SkShader::Context* createContext(const SkBitmap&, const SkPaint&, const SkMatrix&,
                                             void* storage) const SK_OVERRIDE;
    virtual size_t contextSize() const SK_OVERRIDE;

    class SweepGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        SweepGradientContext(const SkSweepGradient& shader, const SkBitmap& device,
                             const SkPaint& paint, const SkMatrix& matrix);
        ~SweepGradientContext() {}

        virtual void shadeSpan(int x, int y, SkPMColor dstC[], int count) SK_OVERRIDE;
        virtual void shadeSpan16(int x, int y, uint16_t dstC[], int count) SK_OVERRIDE;

    private:
        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

    virtual BitmapType asABitmap(SkBitmap* bitmap,
                                 SkMatrix* matrix,
                                 TileMode* xy) const SK_OVERRIDE;

    virtual GradientType asAGradient(SkShader::GradientInfo* info) const SK_OVERRIDE;

    virtual GrEffectRef* asNewEffect(GrContext* context, const SkPaint&) const SK_OVERRIDE;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkSweepGradient)

protected:
    SkSweepGradient(SkReadBuffer& buffer);
    virtual void flatten(SkWriteBuffer& buffer) const SK_OVERRIDE;

private:
    const SkPoint fCenter;

    typedef SkGradientShaderBase INHERITED;
};

#endif