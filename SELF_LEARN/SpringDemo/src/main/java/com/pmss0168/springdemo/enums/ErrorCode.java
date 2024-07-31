package com.pmss0168.springdemo.exception;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;


@Getter
@AllArgsConstructor
@NoArgsConstructor
public enum ErrorCode {
    USER_EXISTS(1001, "User already exists"),
    USER_NOT_EXISTS(1002, "User already exists"),
    USER_NOT_FOUND(1003, "User not found"),
    USERNAME_INVALID(2001, "Username must be at 8-36 characters"),
    PASSWORD_INVALID(2002, "Password must be at 8-36 characters"),
    UNAUTHENTICATED(2003, "Authentication failed"),
    UNCATEGORIZED_ERROR(8888, "Uncategorized error"),
    ;
    private int code;
    private String message;
}
