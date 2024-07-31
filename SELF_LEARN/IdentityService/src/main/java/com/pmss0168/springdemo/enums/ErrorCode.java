package com.pmss0168.springdemo.enums;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.HttpStatusCode;


@Getter
@AllArgsConstructor
@NoArgsConstructor
public enum ErrorCode {
    USER_EXISTS(1001, "User already exists", HttpStatus.BAD_REQUEST),
    USER_NOT_EXISTS(1002, "User already exists", HttpStatus.BAD_REQUEST),
    USER_NOT_FOUND(1003, "User not found", HttpStatus.BAD_REQUEST),
    USERNAME_INVALID(1004, "Username must be at 8-36 characters", HttpStatus.BAD_REQUEST),
    PASSWORD_INVALID(1005, "Password must be at 8-36 characters", HttpStatus.BAD_REQUEST),
    BIRTHDAY_INVALID(1006, "You must old than 18 years old", HttpStatus.BAD_REQUEST),
    UNAUTHENTICATED(2001, "Authentication failed", HttpStatus.UNAUTHORIZED),
    UNAUTHORIZED(2002, "You don't have permission", HttpStatus.FORBIDDEN),
    UNCATEGORIZED_ERROR(9999, "Uncategorized error", HttpStatus.INTERNAL_SERVER_ERROR),
    ;
    private int code;
    private String message;
    private HttpStatusCode statusCode;
}
