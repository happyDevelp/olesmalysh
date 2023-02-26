package com.example.fishermanhandbook

import android.os.Bundle
import android.os.PersistableBundle
import android.webkit.WebView
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class ContentActivity: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.content_layout)

/*
        var webView = findViewById<WebView>(R.id.webVIew)
        webView.loadUrl("file:///android_asset/som_item.html")*/

        var tvtitle = findViewById<TextView>(R.id.tv_title)
        var tvcontent = findViewById<TextView>(R.id.tv_content)
        var im = findViewById<ImageView>(R.id.imag)

        tvtitle.text =intent.getStringExtra("title")
        tvcontent.text =intent.getStringExtra("content")
        im.setImageResource(intent.getIntExtra("image", R.drawable.som))


    }
}