{
    "targets": [
        {
            "target_name": "textdetector",
            "dependencies": [
                "third-party/bindings/leptonica.gyp:leptonica",
                "third-party/bindings/tesseract.gyp:tesseract",
                "third-party/bindings/opencv.gyp:opencv",
                "native/ocr/ocr.gyp:ocr"
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "native"
            ],
            "sources": [
                "native/index.cc",
                "native/async.cc",
                "native/sync.cc"
            ]
        }
    ]
}
