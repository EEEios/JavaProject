package com.controller;

import com.pojo.User;
import com.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;


@Controller
public class LoginController {

    @Autowired
    private UserService userService;

    @RequestMapping("toRegister")
    public String toRegister(){
        return "register";
    }

    @RequestMapping("register")
    public String Register(User info){
        info.setPower(0);
        userService.addUser(info);
        return "redirect:login";
    }

    @RequestMapping("login")
    public String Login(User info){
        User user = userService.login(info);
        if (user != null) {
            if(user.getPower()==1){
                return "admin";
            }else{
                return "redirect:/ordinary/listMusic";
            }
        } else {
            return "login";
        }
    }
}


