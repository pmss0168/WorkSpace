package com.pmss0168.springdemo.controller;

import com.pmss0168.springdemo.dto.request.APIResponse;
import com.pmss0168.springdemo.dto.request.UserCreationRequest;
import com.pmss0168.springdemo.dto.request.UserUpdateRequest;
import com.pmss0168.springdemo.dto.response.UserResponse;
import com.pmss0168.springdemo.entity.User;
import com.pmss0168.springdemo.service.UserService;
import jakarta.validation.Valid;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/users")
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class UserController {
    private static final Logger log = LoggerFactory.getLogger(UserController.class);
    UserService userService;

    @PostMapping
    public APIResponse<UserResponse> createUser(@RequestBody @Valid UserCreationRequest user) {
        return APIResponse.<UserResponse>builder()
                .result(userService.create(user))
                .build();
    }

    @GetMapping
    public APIResponse<List<UserResponse>> getAllUsers() {
        //Get token from header
        var authentication = SecurityContextHolder.getContext().getAuthentication();
        log.info("Username : {}", authentication.getName());
        authentication.getAuthorities().forEach(grantedAuthority -> log.info("GrantedAuthority : {}", grantedAuthority.getAuthority()));
        return APIResponse.<List<UserResponse>>builder()
                .result(userService.getAll())
                .build();
    }

    @GetMapping("/{userId}")
    public APIResponse<UserResponse> getUser(@PathVariable String userId) {
        return APIResponse.<UserResponse>builder()
                .result(userService.getById(userId))
                .build();
    }

    @PutMapping("/{userId}")
    public APIResponse<UserResponse> updateUser(@PathVariable String userId ,@RequestBody UserUpdateRequest request){
        return APIResponse.<UserResponse>builder()
                .result(userService.update(userId, request))
                .build();
    }

    @DeleteMapping("/{userId}")
    public APIResponse<Void> deleteUser(@PathVariable String userId){
        userService.deleteById(userId);
        return APIResponse.<Void>builder().build();
    }

    @GetMapping("/my-info")
    public APIResponse<UserResponse> getMyInfo() {
        return APIResponse.<UserResponse>builder()
                .result(userService.getMyInfo())
                .build();
    }
}
