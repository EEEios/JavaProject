package com.service;

import com.pojo.Music;

import java.util.List;

public interface MusicService {
    void addMusic(Music music) ;
    void deleteMusic(long id);
    void updateMusic(Music music);
    Music queryMusicById(long id);
    List<Music> queryAllMusic();
    List<Music> searchMusic(String str);
}
