{
    "targets": [
        {
            "target_name": "text-detection",
            "sources": [
                "./native/index.cc",
                "./native/pi_est.cc",
                "./native/sync.cc",
                "./native/async.cc"
            ],
            "include_dirs": ["<!(node -e \"require('nan')\")"]
        }
    ]
}