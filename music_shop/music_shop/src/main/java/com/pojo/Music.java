package com.pojo;

import java.sql.Date;

public class Music {
    private long musicId;
    private String musicName;
    private String musicArtist;
    private String musicAlbum;
    private long musicIdInAlbum;
    private Date musicDate;
    private long musicPrice;

    public long getMusicId() {
        return musicId;
    }

    public void setMusicId(long musicId) {
        this.musicId = musicId;
    }

    public String getMusicName() {
        return musicName;
    }

    public void setMusicName(String musicName) {
        this.musicName = musicName;
    }

    public String getMusicArtist() {
        return musicArtist;
    }

    public void setMusicArtist(String musicArtist) {
        this.musicArtist = musicArtist;
    }

    public String getMusicAlbum() {
        return musicAlbum;
    }

    public void setMusicAlbum(String musicAlbum) {
        this.musicAlbum = musicAlbum;
    }

    public long getMusicIdInAlbum() {
        return musicIdInAlbum;
    }

    public void setMusicIdInAlbum(long musicIdInAlbum) {
        this.musicIdInAlbum = musicIdInAlbum;
    }

    public Date getMusicDate() {
        return musicDate;
    }

    public void setMusicDate(Date musicDate) {
        this.musicDate = musicDate;
    }

    public long getMusicPrice() {
        return musicPrice;
    }

    public void setMusicPrice(long musicPrice) {
        this.musicPrice = musicPrice;
    }
}