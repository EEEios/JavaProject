package com.service.impl;

import com.dao.UserDao;
import com.pojo.User;
import com.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserServiceImpl implements UserService {

    @Autowired
    private UserDao userDao;

    @Override
    public void addUser(User user){
        userDao.addUser(user);
    }

    @Override
    public void deleteUser(long id){
        userDao.deleteUserById(id);
    }

    @Override
    public void updateUser(User user){
        userDao.updateUser(user);
    }

    @Override
    public User queryUserById(long id){
        return userDao.queryUserById(id);
    }

    @Override
    public List<User> queryAllUser(){
        List<User> list = userDao.queryAllUser();
        return list;
    }

    @Override
    public List<User> searchUser(String str){
        List<User> users = userDao.searchUser(str);
        return users;
    }

    @Override
    public User login(User info){
        User user = userDao.login(info);
        return user;
    }


}
