package com.dao;

import java.util.List;

import com.pojo.User;

public interface UserDao {

    void addUser(User user);

    void deleteUserById(long id);

    void updateUser(User user);

    User queryUserById(long id);

    List<User> queryAllUser();

    List<User> searchUser(String str);

    User login(User user);
}