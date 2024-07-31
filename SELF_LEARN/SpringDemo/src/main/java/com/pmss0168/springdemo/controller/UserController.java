package com.pmss0168.springdemo.controller;

import com.pmss0168.springdemo.dto.APIResponse;
import com.pmss0168.springdemo.dto.UserCreationRequest;
import com.pmss0168.springdemo.dto.UserUpdateRequest;
import com.pmss0168.springdemo.entity.User;
import com.pmss0168.springdemo.service.UserService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/users")
public class UserController {
    @Autowired
    private UserService userService;

    @PostMapping
    public APIResponse<User> createUser(@RequestBody @Valid UserCreationRequest user) {
        APIResponse<User> apiResponse = new APIResponse<>();
        apiResponse.setResult(userService.createUser(user));
        return apiResponse;
    }
    @GetMapping
    public List<User> getAllUsers() {
        return userService.getAllUsers();
    }
    @GetMapping("/{userId}")
    public User getUser(@PathVariable String userId) {
        return userService.getUserById(userId);
    }
    @PutMapping("/{userId}")
    public User updateUser(@PathVariable String userId ,@RequestBody UserUpdateRequest request){
        return userService.updateUser(userId, request);
    }
    @DeleteMapping("/{userId}")
    public void deleteUser(@PathVariable String userId){
        userService.removeUser(userId);
    }
}
