package com.pmss0168.cruddemo.controller;


import org.springframework.web.bind.annotation.*;
import org.springframework.ui.Model;

@RestController
@RequestMapping("/")
public class RestController {
    @GetMapping("/hello")
    public String hello(Model model) {
        model.addAttribute("message", "Hello World");
        return "hello";
    }
}
