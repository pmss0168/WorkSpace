package com.pmss0168.springdemo.exception;

import lombok.*;
import lombok.experimental.SuperBuilder;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class AppException extends RuntimeException{
    private ErrorCode errorCode;
}
