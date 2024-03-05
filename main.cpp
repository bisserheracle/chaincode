void WavImporter::doClose() { _data = Containers::NullOpt; }

BufferFormat WavImporter::doFormat() const { return _format; }

UnsignedInt WavImporter::doFrequency() const { return _frequency; }

Containers::Array<char> WavImporter::doData() {
    Containers::Array<char> copy{NoInit, _data->size()};
    Utility::copy(*_data, copy);
    return copy;
}

 else if((header.imageType & ~8) == 3) {
        format = PixelFormat::R8Unorm;
        if(header.bpp != 8) {
            Error() << "Trade::TgaImporter::image2D(): unsupported grayscale bits-per-pixel:" << header.bpp;
            return {};
        }

    /* Other? */
    } else {
        Error() << "Trade::TgaImporter::image2D(): unsupported image type:" << header.imageType;
        return {};
    }
//helo
    if(Containers::StringView{_in}.hasSuffix("TRUEVISION-XFILE.\0"_s)) {
        if(srcPixels.size() < sizeof(Implementation::TgaFooter)) {
            Error{} << "Trade::TgaImporter::image2D(): TGA 2 file too short, expected at least" << sizeof(Implementation::TgaHeader) + sizeof(Implementation::TgaFooter) << "bytes but got" << _in.size();
            return {};
