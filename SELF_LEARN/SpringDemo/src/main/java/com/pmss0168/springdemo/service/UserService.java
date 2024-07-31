package com.pmss0168.springdemo.service;

import com.pmss0168.springdemo.dto.UserCreationRequest;
import com.pmss0168.springdemo.dto.UserUpdateRequest;
import com.pmss0168.springdemo.entity.User;
import com.pmss0168.springdemo.exception.AppException;
import com.pmss0168.springdemo.exception.ErrorCode;
import com.pmss0168.springdemo.mapper.UserMapper;
import com.pmss0168.springdemo.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService {
    @Autowired
    private UserRepository userRepository;
    @Autowired
    private UserMapper userMapper;

    public User createUser(UserCreationRequest request) {
        if(userRepository.existsByUsername(request.getUsername())) {
            throw new AppException(ErrorCode.USER_EXISTS);
        }
        User user = userMapper.toUser(request);
//        User user = User.builder()
//                .password(request.getPassword())
//                .firstName(request.getFirstName())
//                .lastName(request.getLastName())
//                .birthDate(request.getBirthDate())
//                .build();
        return userRepository.save(user);
    }
    public List<User> getAllUsers() {
        return userRepository.findAll();
    }
    public User getUserById(String userId) {
        return userRepository.findById(userId).orElseThrow(() -> new RuntimeException("User not found"));
    }
    public User updateUser(String userId, UserUpdateRequest user) {
        User userUpdate = getUserById(userId);
        userUpdate.setPassword(user.getPassword());
        userUpdate.setFirstName(user.getFirstName());
        userUpdate.setLastName(user.getLastName());
        userUpdate.setBirthDate(user.getBirthDate());
        return  userRepository.save(userUpdate);
    }
    public void removeUser(String userId) {
        userRepository.deleteById(userId);
    }
}
