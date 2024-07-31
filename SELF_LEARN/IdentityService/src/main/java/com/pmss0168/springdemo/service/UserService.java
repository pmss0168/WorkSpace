package com.pmss0168.springdemo.service;

import com.pmss0168.springdemo.dto.request.UserCreationRequest;
import com.pmss0168.springdemo.dto.request.UserUpdateRequest;
import com.pmss0168.springdemo.dto.response.UserResponse;
import com.pmss0168.springdemo.entity.User;
import com.pmss0168.springdemo.enums.Role;
import com.pmss0168.springdemo.exception.AppException;
import com.pmss0168.springdemo.enums.ErrorCode;
import com.pmss0168.springdemo.mapper.UserMapper;
import com.pmss0168.springdemo.repository.RoleRepository;
import com.pmss0168.springdemo.repository.UserRepository;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.security.access.prepost.PostAuthorize;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.HashSet;
import java.util.List;
import java.util.Optional;

@Service
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class UserService {
    UserRepository userRepository;
    UserMapper userMapper;
    PasswordEncoder passwordEncoder;
    private final RoleRepository roleRepository;

    public UserResponse create(UserCreationRequest request) {
        if(userRepository.existsByUsername(request.getUsername())) {
            throw new AppException(ErrorCode.USER_EXISTS);
        }
        User user = userMapper.toUser(request);
        user.setPassword(passwordEncoder.encode(request.getPassword()));
        HashSet<String> roles = new HashSet<>();
        roles.add(Role.USER.name());
//        user.setRoles(roles);
        return userMapper.toUserResponse(userRepository.save(user));
    }

//    @PreAuthorize("hasRole('ADMIN')")   //Check authorize before excuse method
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN', 'CREATE_DATA')")
    public List<UserResponse> getAll() {
        var users = userRepository.findAll();
        return users.stream().map(userMapper::toUserResponse).toList();
    }

    @PostAuthorize("returnObject.username == authentication.name")   //Check after excuse method
    public UserResponse getById(String userId) {
        return userMapper.toUserResponse(userRepository.findById(userId).orElseThrow(() -> new RuntimeException("User not found")));
    }

    public UserResponse update(String userId, UserUpdateRequest request) {
        User user = userRepository.findById(userId).orElseThrow(() -> new RuntimeException("User not found"));
        userMapper.updateUser(user, request);
        var roles = roleRepository.findAllById(request.getRoles());
        user.setRoles(new HashSet<>(roles));

        return  userMapper.toUserResponse(userRepository.save(user));
    }

    public void deleteById(String userId) {
        userRepository.deleteById(userId);
    }

    public UserResponse getMyInfo(){
        var context = SecurityContextHolder.getContext();
        String name = context.getAuthentication().getName();
        User info = userRepository.findByUsername(name).orElseThrow(() -> new AppException(ErrorCode.USER_NOT_EXISTS));
        return userMapper.toUserResponse(info);
    }
}
