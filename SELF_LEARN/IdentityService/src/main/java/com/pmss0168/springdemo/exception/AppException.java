package com.pmss0168.springdemo.exception;

import com.pmss0168.springdemo.enums.ErrorCode;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class AppException extends RuntimeException{
    private ErrorCode errorCode;
}
