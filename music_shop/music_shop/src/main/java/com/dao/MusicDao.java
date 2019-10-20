package com.dao;

import com.pojo.Music;

import java.util.List;

public interface MusicDao {
    void addMusic(Music music);

    void deleteMusicById(long id);

    void updateMusic(Music music);

    Music queryMusicById(long id);

    List<Music> queryAllMusic();

    List<Music> searchMusic(String str);
}
