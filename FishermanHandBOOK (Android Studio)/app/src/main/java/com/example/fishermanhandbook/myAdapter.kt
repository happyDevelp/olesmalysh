package com.example.fishermanhandbook

import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView

class MyAdapter (listArray:ArrayList<listItem>, context: Context): RecyclerView.Adapter<MyAdapter.ViewHolder>()  {
    var listArrarR = listArray
    var contextR = context


    class ViewHolder(view: View): RecyclerView.ViewHolder(view) {
        val tvTitle = view.findViewById<TextView>(R.id.tvTitle)
        val tvContent = view.findViewById<TextView>(R.id.tvContent)
        val imViewSchuka = view.findViewById<ImageView>(R.id.imViewSchuka)


        fun bind( listItem:listItem, context: Context)
            {
            tvTitle.text = listItem.titleText
            var textCon = listItem.contentText
            if (listItem.contentText.length > 100) {
                 textCon = listItem.contentText.substring(0, 100) + "..."
            }
            tvContent.text = textCon
            imViewSchuka.setImageResource(listItem.image_id)

            itemView.setOnClickListener{
                val i = Intent(context, ContentActivity::class.java).apply {
                    putExtra("title", tvTitle.text.toString())
                    putExtra("content", listItem.contentText)
                    putExtra("image", listItem.image_id)
                }
                context.startActivity(i)
            }
        }

    }
    //відео 18 хвилина 9 урок
    //показуємо де ми будемо малювати список
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val inflater = LayoutInflater.from(contextR)
        return ViewHolder(inflater.inflate(R.layout.item_layout,parent,false))
    }

    override fun getItemCount(): Int {
        return listArrarR.size
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        var listItem = listArrarR.get(position)
        holder.bind(listItem,contextR)
    }

    fun updateAdapter(listArray: List<listItem>){
        listArrarR.clear()
        listArrarR.addAll(listArray)
        notifyDataSetChanged()
    }
}