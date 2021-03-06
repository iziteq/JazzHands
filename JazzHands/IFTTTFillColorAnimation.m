//
//  IFTTTFillColorAnimation.m
//  JazzHands
//
//  Created by Pierluigi D'Andrea on 07/05/15.
//  Copyright (c) 2015 IFTTT Inc. All rights reserved.
//

#import "IFTTTJazzHands.h"

@implementation IFTTTFillColorAnimation

- (id)initWithLayer:(CALayer *)layer {
    NSCParameterAssert([layer isKindOfClass:CAShapeLayer.class]);
    return [super initWithLayer:layer];
}

- (void)animate:(NSInteger)time
{
    if (self.keyFrames.count <= 1) return;
    
    IFTTTAnimationFrame *animationFrame = [self animationFrameForTime:time];
    ((CAShapeLayer *)self.layer).fillColor = animationFrame.color.CGColor;
}


- (IFTTTAnimationFrame *)frameForTime:(NSInteger)time
                        startKeyFrame:(IFTTTAnimationKeyFrame *)startKeyFrame
                          endKeyFrame:(IFTTTAnimationKeyFrame *)endKeyFrame
{
    IFTTTAnimationFrame *animationFrame = [IFTTTAnimationFrame new];
    
    CGFloat startRed, startBlue, startGreen, startAlpha;
    CGFloat endRed = 0, endBlue = 0, endGreen = 0, endAlpha = 0;
    
    if ([self iftttGetRed:&startRed green:&startGreen blue:&startBlue alpha:&startAlpha fromColor:startKeyFrame.color] &&
        [self iftttGetRed:&endRed green:&endGreen blue:&endBlue alpha:&endAlpha fromColor:endKeyFrame.color]) {
        CGFloat red = [self tweenValueForStartTime:startKeyFrame.time endTime:endKeyFrame.time startValue:startRed endValue:endRed atTime:time];
        CGFloat green = [self tweenValueForStartTime:startKeyFrame.time endTime:endKeyFrame.time startValue:startGreen endValue:endGreen atTime:time];
        CGFloat blue = [self tweenValueForStartTime:startKeyFrame.time endTime:endKeyFrame.time startValue:startBlue endValue:endBlue atTime:time];
        CGFloat alpha = [self tweenValueForStartTime:startKeyFrame.time endTime:endKeyFrame.time startValue:startAlpha endValue:endAlpha atTime:time];
        animationFrame.color = [UIColor colorWithRed:red green:green blue:blue alpha:alpha];
    }
    
    return animationFrame;
}

- (BOOL) iftttGetRed:(CGFloat *)red green:(CGFloat *)green blue:(CGFloat *)blue alpha:(CGFloat *)alpha fromColor:(UIColor *)color {
    CGFloat white;
    
    if ([color getRed:red green:green blue:blue alpha:alpha]) {
        return YES;
    } else if ([color getWhite:&white alpha:alpha]) {
        *red = white;
        *green = white;
        *blue = white;
        return YES;
    }
    
    return NO;
}

@end
