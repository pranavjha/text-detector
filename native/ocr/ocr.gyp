{
    "targets": [
        {
            "target_name": "ocr",
            "type": "static_library",
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "../",
            ],
            "sources": [
                "./ocr.cpp"
            ]
        }
    ]
}
