{
    "targets": [
        {
            "target_name": "text-detection",
            "sources": [
                "./lib/native/addon.cc",
                "./lib/native/pi_est.cc",
                "./lib/native/sync.cc",
                "./lib/native/async.cc"
            ],
            "include_dirs": ["<!(node -e \"require('nan')\")"]
        }
    ]
}