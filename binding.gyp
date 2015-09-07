{
    "targets": [
        {
            "target_name": "textdetector",
            "dependencies": [
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