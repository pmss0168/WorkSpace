package com.pmss0168.springdemo.mapper;

import com.pmss0168.springdemo.dto.request.UserCreationRequest;
import com.pmss0168.springdemo.dto.request.UserUpdateRequest;
import com.pmss0168.springdemo.dto.response.UserResponse;
import com.pmss0168.springdemo.entity.User;
import org.mapstruct.Mapper;
import org.mapstruct.MappingTarget;

import java.util.List;

@Mapper(componentModel = "spring")
public interface UserMapper {
    User toUser(UserCreationRequest request);
    UserResponse toUserResponse(User user);
    List<UserResponse> toUserResponseList(List<User> users);
    void updateUser(@MappingTarget User user, UserUpdateRequest request);
}
