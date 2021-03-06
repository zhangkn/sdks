//
//  INStartWorkoutIntent.h
//  Intents
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Intents/INIntent.h>
#import <Intents/INIntentResolutionResult.h>

#import <Intents/INWorkoutGoalUnitType.h>
#import <Intents/INWorkoutLocationType.h>

@class INSpeakableString;
@class INSpeakableStringResolutionResult;
@class INDoubleResolutionResult;
@class INWorkoutGoalUnitTypeResolutionResult;
@class INWorkoutLocationTypeResolutionResult;
@class INBooleanResolutionResult;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0))
API_UNAVAILABLE(macosx)
@interface INStartWorkoutIntent : INIntent

- (instancetype)initWithWorkoutName:(nullable INSpeakableString *)workoutName
                          goalValue:(nullable NSNumber *)goalValue
                workoutGoalUnitType:(INWorkoutGoalUnitType)workoutGoalUnitType
                workoutLocationType:(INWorkoutLocationType)workoutLocationType
                        isOpenEnded:(nullable NSNumber *)isOpenEnded NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INSpeakableString *workoutName;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *goalValue NS_REFINED_FOR_SWIFT;

@property (readonly, assign, NS_NONATOMIC_IOSONLY) INWorkoutGoalUnitType workoutGoalUnitType;

@property (readonly, assign, NS_NONATOMIC_IOSONLY) INWorkoutLocationType workoutLocationType;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *isOpenEnded NS_REFINED_FOR_SWIFT;

@end

@class INStartWorkoutIntentResponse;

/*!
 @brief Protocol to declare support for handling an INStartWorkoutIntent 
 @abstract By implementing this protocol, a class can provide logic for resolving, confirming and handling the intent.
 @discussion The minimum requirement for an implementing class is that it should be able to handle the intent. The resolution and confirmation methods are optional. The handling method is always called last, after resolving and confirming the intent.
 */

API_AVAILABLE(ios(10.0))
API_UNAVAILABLE(macosx)
@protocol INStartWorkoutIntentHandling <NSObject>

@required

/*!
 @brief handling method

 @abstract Execute the task represented by the INStartWorkoutIntent that's passed in
 @discussion This method is called to actually execute the intent. The app must return a response for this intent.

 @param  startWorkoutIntent The input intent
 @param  completion The response handling block takes a INStartWorkoutIntentResponse containing the details of the result of having executed the intent

 @see  INStartWorkoutIntentResponse
 */

- (void)handleStartWorkout:(INStartWorkoutIntent *)intent
                completion:(void (^)(INStartWorkoutIntentResponse *response))completion NS_SWIFT_NAME(handle(startWorkout:completion:));

@optional

/*!
 @brief Confirmation method
 @abstract Validate that this intent is ready for the next step (i.e. handling)
 @discussion These methods are called prior to asking the app to handle the intent. The app should return a response object that contains additional information about the intent, which may be relevant for the system to show the user prior to handling. If unimplemented, the system will assume the intent is valid following resolution, and will assume there is no additional information relevant to this intent.

 @param  startWorkoutIntent The input intent
 @param  completion The response block contains an INStartWorkoutIntentResponse containing additional details about the intent that may be relevant for the system to show the user prior to handling.

 @see INStartWorkoutIntentResponse

 */

- (void)confirmStartWorkout:(INStartWorkoutIntent *)intent
                 completion:(void (^)(INStartWorkoutIntentResponse *response))completion NS_SWIFT_NAME(confirm(startWorkout:completion:));

/*!
 @brief Resolution methods
 @abstract Determine if this intent is ready for the next step (confirmation)
 @discussion These methods are called to make sure the app extension is capable of handling this intent in its current form. This method is for validating if the intent needs any further fleshing out.

 @param  startWorkoutIntent The input intent
 @param  completion The response block contains an INIntentResolutionResult for the parameter being resolved

 @see INIntentResolutionResult

 */

- (void)resolveWorkoutNameForStartWorkout:(INStartWorkoutIntent *)intent
                           withCompletion:(void (^)(INSpeakableStringResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveWorkoutName(forStartWorkout:with:));

- (void)resolveGoalValueForStartWorkout:(INStartWorkoutIntent *)intent
                         withCompletion:(void (^)(INDoubleResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveGoalValue(forStartWorkout:with:));

- (void)resolveWorkoutGoalUnitTypeForStartWorkout:(INStartWorkoutIntent *)intent
                                   withCompletion:(void (^)(INWorkoutGoalUnitTypeResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveWorkoutGoalUnitType(forStartWorkout:with:));

- (void)resolveWorkoutLocationTypeForStartWorkout:(INStartWorkoutIntent *)intent
                                   withCompletion:(void (^)(INWorkoutLocationTypeResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveWorkoutLocationType(forStartWorkout:with:));

- (void)resolveIsOpenEndedForStartWorkout:(INStartWorkoutIntent *)intent
                           withCompletion:(void (^)(INBooleanResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveIsOpenEnded(forStartWorkout:with:));

@end

NS_ASSUME_NONNULL_END
