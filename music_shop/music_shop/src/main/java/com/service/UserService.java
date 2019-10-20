package com.service;

import com.pojo.User;

import java.util.List;

public interface UserService {
    void addUser(User user);

    void deleteUser(long id);

    void updateUser(User user);

    User queryUserById(long id);

    List<User> queryAllUser();

    List<User> searchUser(String str);

    User login(User user);
}
