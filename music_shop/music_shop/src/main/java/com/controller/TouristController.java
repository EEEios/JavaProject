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
@RequestMapping("/Tourist")
public class TouristController {

    @Autowired
    private MusicService musicService;

    @RequestMapping("/touristMusic")
    public String list(Model model) {
        List<Music> list;
        list = musicService.queryAllMusic();
        model.addAttribute("tourisMusicList", list);
        return "Tourist/touristMusic";
    }

    @RequestMapping("/touristSearMusic")
    public String searchMusic(Model model,@RequestParam(value="searchStr")String str){
        List<Music> resList;
        resList = musicService.searchMusic(str);
        model.addAttribute("tourisSearList",resList);
        return "Tourist/touristSearMusic";
    }
}
