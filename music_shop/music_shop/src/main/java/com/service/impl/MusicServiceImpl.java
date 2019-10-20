package com.service.impl;

import com.pojo.Music;
import com.dao.MusicDao;
import com.service.MusicService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MusicServiceImpl implements MusicService {

    @Autowired
    private MusicDao musicDao;

    @Override
    public void addMusic(Music music) {
        musicDao.addMusic(music);
    }

    @Override
    public void deleteMusic(long id) {
        musicDao.deleteMusicById(id);
    }

    @Override
    public void updateMusic(Music music) {
        musicDao.updateMusic(music);
    }

    @Override
    public Music queryMusicById(long id) {
        return musicDao.queryMusicById(id);
    }

    @Override
    public List<Music> queryAllMusic() {
        List<Music> musics = musicDao.queryAllMusic();
        return musics;
    }

    @Override
    public List<Music> searchMusic(String str){
        List<Music> musics = musicDao.searchMusic(str);
        return musics;
    }
}
