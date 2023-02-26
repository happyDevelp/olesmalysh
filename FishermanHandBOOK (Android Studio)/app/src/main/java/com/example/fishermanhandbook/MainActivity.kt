package com.example.fishermanhandbook

import android.app.LauncherActivity.ListItem
import android.content.res.TypedArray
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.MenuItem
import android.widget.Toast
import androidx.core.view.GravityCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.fishermanhandbook.databinding.ActivityMainBinding
import com.google.android.material.navigation.NavigationView

class MainActivity : AppCompatActivity(), NavigationView.OnNavigationItemSelectedListener {
    lateinit var binding: ActivityMainBinding
    var adapter: MyAdapter? = null


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        var rcView = findViewById<RecyclerView>(R.id.rcView)
        //Кажемо, що метод onNavigationItemSelected має працювати у всьому цьому класі. без цього не буде працювати
        binding.navView.setNavigationItemSelectedListener (this)


        var list = ArrayList<listItem>()

        list.addAll(fillArrays(resources.getStringArray(R.array.fish_name), resources.getStringArray(R.array.fish_content),
            getImageId(R.array.fish_image_array)))

        rcView.hasFixedSize()
        rcView.layoutManager = LinearLayoutManager(this)

        adapter = MyAdapter(list, this)
        rcView.adapter = adapter


    }

    //like ClickListener but for drawer_menu
    override fun onNavigationItemSelected(item: MenuItem): Boolean {
        when (item.itemId){
            R.id.id_fish -> {
                adapter?.updateAdapter(fillArrays(resources.getStringArray(R.array.fish_name), resources.getStringArray(R.array.fish_content),
                    getImageId(R.array.fish_image_array)))
            }
            R.id.id_bait -> {
                adapter?.updateAdapter(fillArrays(resources.getStringArray(R.array.bind_name), resources.getStringArray(R.array.bind_content),
                getImageId(R.array.bind_image_array)))
            }
            R.id.id_fishFloat -> {
                adapter?.updateAdapter(fillArrays(resources.getStringArray(R.array.snasty_name), resources.getStringArray(R.array.snasty_content),
                    getImageId(R.array.snasty_image_array)))
            }
            R.id.id_history -> {
                adapter?.updateAdapter(fillArrays(resources.getStringArray(R.array.history_name), resources.getStringArray(R.array.history_content),
                    getImageId(R.array.history_image_array)))
            }

        }
        binding.idDrawerLayout.closeDrawer(GravityCompat.START)
        return true
    }

    //заповнюємо лист данними з array
    fun fillArrays(titleArray: Array<String>, contentArray: Array<String>, imageArray: IntArray):List<listItem>{
        var listItemArray = ArrayList<listItem>()

        for (n in 0..titleArray.size -1){
            var listItemm = listItem(imageArray[n], titleArray[n], contentArray[n])
            listItemArray.add(listItemm)
        }
        return listItemArray
    }


    fun getImageId(imageArrayId: Int):IntArray{
        //разшифровуем полученый массив
        var tArray: TypedArray = resources.obtainTypedArray(imageArrayId)
        var count = tArray.length()
        var ids = IntArray(count)

        for (n in ids.indices){
            ids[n] = tArray.getResourceId(n, 0)
        }
        tArray.recycle()
        return ids
    }
}