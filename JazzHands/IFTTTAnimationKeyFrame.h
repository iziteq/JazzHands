//
//  IFTTTAnimationKeyFrame.h
//  JazzHands
//
//  Created by Devin Foley on 9/27/13.
//  Copyright (c) 2013 IFTTT Inc. All rights reserved.
//

#import "IFTTTAnimationFrame.h"
#import "IFTTTEasingFunction.h"

@interface IFTTTAnimationKeyFrame : IFTTTAnimationFrame

// These variadic methods require arguments to be of the form
//
//      n, time_1, value_1, time_2, value_2, ..., time_n, value_n,
//
// where n is the number of time-value pairs. That is, the number of pairs must be the
// first argument, then the method will take care of unpacking the rest of the times and
// values into keyframe objects.
//
+ (NSArray *)keyFramesWithTimesAndAlphas:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndCornerRadius:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndFrames:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndHiddens:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndColors:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndAngles:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndTransform3D:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndScales:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndConstraint:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndStrokeStarts:(NSInteger)pairCount,...;
+ (NSArray *)keyFramesWithTimesAndStrokeEnds:(NSInteger)pairCount,...;

+ (instancetype)keyFrameWithTime:(NSInteger)time andAlpha:(CGFloat)alpha;
+ (instancetype)keyFrameWithTime:(NSInteger)time andCornerRadius:(CGFloat)cornerRadius;
+ (instancetype)keyFrameWithTime:(NSInteger)time andFrame:(CGRect)frame;
+ (instancetype)keyFrameWithTime:(NSInteger)time andHidden:(BOOL)hidden;
+ (instancetype)keyFrameWithTime:(NSInteger)time andColor:(UIColor*)color;
+ (instancetype)keyFrameWithTime:(NSInteger)time andAngle:(CGFloat)angle;
+ (instancetype)keyFrameWithTime:(NSInteger)time andTransform3D:(IFTTTTransform3D *)transform;
+ (instancetype)keyFrameWithTime:(NSInteger)time andScale:(CGFloat)scale;
+ (instancetype)keyFrameWithTime:(NSInteger)time andConstraint:(CGFloat)constraint;
+ (instancetype)keyFrameWithTime:(NSInteger)time andStrokeStart:(CGFloat)strokeStart;
+ (instancetype)keyFrameWithTime:(NSInteger)time andStrokeEnd:(CGFloat)strokeEnd;

- (id)initWithTime:(NSInteger)time andAlpha:(CGFloat)alpha;
- (id)initWithTime:(NSInteger)time andCornerRadius:(CGFloat)cornerRadius;
- (id)initWithTime:(NSInteger)time andFrame:(CGRect)frame;
- (id)initWithTime:(NSInteger)time andHidden:(BOOL)hidden;
- (id)initWithTime:(NSInteger)time andColor:(UIColor*)color;
- (id)initWithTime:(NSInteger)time andAngle:(CGFloat)angle;
- (id)initWithTime:(NSInteger)time andTransform3D:(IFTTTTransform3D *)transform;
- (id)initWithTime:(NSInteger)time andScale:(CGFloat)scale;
- (id)initWithTime:(NSInteger)time andConstraint:(CGFloat)constraint;
- (id)initWithTime:(NSInteger)time andStrokeStart:(CGFloat)strokeStart;
- (id)initWithTime:(NSInteger)time andStrokeEnd:(CGFloat)strokeEnd;

@property (assign, nonatomic) NSInteger time;

/**
 *  The easing function defines the rate of change in your key frames over time.
 *  By default, IFTTTEasingFunctionLinear.
 *
 *  @see IFTTTEasingFunction.h
 */
@property (copy, nonatomic) IFTTTEasingFunction easingFunction;

@end
