package com.controller;

import com.pojo.User;
import com.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
@RequestMapping("/user")
public class UserController {

    @Autowired
    private UserService userService;

    @RequestMapping("/allUser")
    public String list(Model model) {
        List<User> list;
        list = userService.queryAllUser();
        model.addAttribute("userlist", list);
        return "User/allUser";
    }

    @RequestMapping("/searchUser")
    public String searchUser(Model model,@RequestParam(value="searchStr")String str){
        List<User> resList;
        resList = userService.searchUser(str);
        model.addAttribute("searchRes",resList);
        return "User/searchUser";
    }

    @RequestMapping("toAddUser")
    public String toAddUser() {
        return "User/addUser";
    }

    @RequestMapping("/addUser")
    public String addUser(User user) {
        userService.addUser(user);
        return "redirect:/user/allUser";
    }

    @RequestMapping("/del/{userId}")
    public String deleteUser(@PathVariable("userId") Long id) {
        userService.deleteUser(id);
        return "redirect:/user/allUser";
    }

    @RequestMapping("toUpdateUser")
    public String toUpdateUser(Model model, Long id) {
        model.addAttribute("user", userService.queryUserById(id));
        return "User/updateUser";
    }

    @RequestMapping("/updateUser")
    public String updateUser(Model model, User user) {
        userService.updateUser(user);
        user = userService.queryUserById(user.getUserId());
        model.addAttribute("user", user);
        return "redirect:/user/allUser";
    }

}


