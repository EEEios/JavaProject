package com.controller;

import com.pojo.Music;
import com.service.MusicService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
@RequestMapping("/ordinary")
public class OrdinaryController {

    @Autowired
    private MusicService musicService;


    @RequestMapping("/collect")
    public String collect(Model model) {
        List<Music> list;
        list = musicService.queryAllMusic();
        model.addAttribute("collectlist", list);
        return "ordinary/collect";
    }

    @RequestMapping("/listMusic")
    public String list(Model model) {
        List<Music> list;
        list = musicService.queryAllMusic();
        model.addAttribute("musiclist", list);
        return "ordinary/listMusic";
    }

    @RequestMapping("/searMusic")
    public String searchMusic(Model model,@RequestParam(value="searchStr")String str){
        List<Music> resList;
        resList = musicService.searchMusic(str);
        model.addAttribute("searchRes",resList);
        return "ordinary/searMusic";
    }
}
