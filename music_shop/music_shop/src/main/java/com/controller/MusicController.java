package com.controller;

import com.pojo.Music;
import com.service.MusicService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
@RequestMapping("/music")
public class MusicController {

    @Autowired
    private MusicService musicService;

    @RequestMapping("/allMusic")
    public String list(Model model) {
        List<Music> list;
        list = musicService.queryAllMusic();
        model.addAttribute("musiclist", list);
        return "Music/allMusic";
    }

    @RequestMapping("/searchMusic")
    public String searchMusic(Model model,@RequestParam(value="searchStr")String str){
        List<Music> resList;
        resList = musicService.searchMusic(str);
        model.addAttribute("searchRes",resList);
        return "Music/searchMusic";
    }

    @RequestMapping("toAddMusic")
    public String toAddMusic() {
        return "Music/addMusic";
    }

    @RequestMapping("/addMusic")
    public String addMusic(Music music) {
        musicService.addMusic(music);
        return "redirect:/music/allMusic";
    }

    @RequestMapping("/del/{musicId}")
    public String deleteMusic(@PathVariable("musicId") Long id) {
        musicService.deleteMusic(id);
        return "redirect:/music/allMusic";
    }

    @RequestMapping("toUpdateMusic")
    public String toUpdateMusic(Model model, Long id) {
        model.addAttribute("music", musicService.queryMusicById(id));
        return "Music/updateMusic";
    }

    @RequestMapping("/updateMusic")
    public String updateMusic(Model model, Music music) {
        musicService.updateMusic(music);
        music = musicService.queryMusicById(music.getMusicId());
        model.addAttribute("music", music);
        return "redirect:/music/allMusic";
    }

}


