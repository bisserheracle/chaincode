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
