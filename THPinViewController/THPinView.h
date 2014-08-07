//
//  THPinView.h
//  THPinViewControllerExample
//
//  Created by Thomas Heß on 21.4.14.
//  Copyright (c) 2014 Thomas Heß. All rights reserved.
//

@import UIKit;
#import "THPinViewControllerMacros.h"
#import "THPinInputCirclesView.h"
#import "THPinNumPadView.h"

@class THPinView;

@protocol THPinViewDelegate <NSObject>

@required
- (NSUInteger)pinLengthForPinView:(THPinView *)pinView;
- (BOOL)pinView:(THPinView *)pinView isPinValid:(NSString *)pin;
- (void)cancelButtonTappedInPinView:(THPinView *)pinView;
- (void)correctPinWasEnteredInPinView:(THPinView *)pinView;
- (void)incorrectPinWasEnteredInPinView:(THPinView *)pinView;

@optional
- (void)numberTappedInPinView:(THPinView *)pinView;
- (void)pin:(NSString *)pin wasEnteredInPinView:(THPinView *)pinView;

@end

@interface THPinView : UIView

@property (nonatomic, weak) id<THPinViewDelegate> delegate;
@property (nonatomic, copy) NSString *promptTitle;
@property (nonatomic, strong) UIColor *promptColor;
@property (nonatomic, assign) BOOL hideLetters;
@property (nonatomic, assign) BOOL disableCancel;
@property (nonatomic, strong) THPinInputCirclesView *inputCirclesView;
@property (nonatomic, strong) THPinNumPadView *numPadView;

- (instancetype)initWithDelegate:(id<THPinViewDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@end
