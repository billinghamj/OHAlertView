//
//  OHAlertView.h
//  AliSoftware
//
//  Created by Olivier on 30/12/10.
//  Copyright 2010 AliSoftware. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OHAlertView : UIAlertView

typedef void(^OHAlertViewButtonHandler)(OHAlertView* alert, NSInteger buttonIndex);
@property (nonatomic, copy) OHAlertViewButtonHandler buttonHandler;

/////////////////////////////////////////////////////////////////////////////

/**
 *	Create and immediately display an AlertView.
 *
 *	@param	title	The title of the AlertView (see UIAlertView)
 *	@param	message	The message of the AlertView (see UIAlertView)
 *	@param	cancelButtonTitle	The title for the "cancel" button (see UIAlertView)
 *	@param	otherButtonTitles	A NSArray of NSStrings containing titles for the other buttons (see UIAlertView)
 *	@param	handler	The block that will be executed when the user taps on a button. This block takes:
 *          - The OHAlertView as its first parameter, useful to get the firstOtherButtonIndex from it for example
 *          - The NSInteger as its second parameter, representing the index of the button that has been tapped
 */
+(void)showAlertWithTitle:(NSString *)title
                  message:(NSString *)message
             cancelButton:(NSString *)cancelButtonTitle
             otherButtons:(NSArray *)otherButtonTitles
            buttonHandler:(OHAlertViewButtonHandler)handler;

/**
 *	Create and immediately display an AlertView with two buttons.
 *
 *	@param	title	The title of the AlertView (see UIAlertView)
 *	@param	message	The message of the AlertView (see UIAlertView)
 *	@param	cancelButtonTitle	The title for the "cancel" button (see UIAlertView)
 *	@param	okButton	The title of the second button
 *	@param	handler	The block that will be executed when the user taps on a button. This block takes:
 *          - The OHAlertView as its first parameter, useful to get the firstOtherButtonIndex from it for example
 *          - The NSInteger as its second parameter, representing the index of the button that has been tapped
 *
 *  @note This is a commodity method, equivalent of calling showAlertWithTitle:cancelButton:otherButtons:buttonHandler: with @[okButton] for the "otherButtons:" parameter
 */
+(void)showAlertWithTitle:(NSString *)title
                  message:(NSString *)message
             cancelButton:(NSString *)cancelButtonTitle
                 okButton:(NSString *)okButton // same as using a 1-item array for otherButtons
            buttonHandler:(OHAlertViewButtonHandler)handler;

/**
 *	Create and immediately display an AlertView with only one button.
 *
 *	@param	title	The title of the AlertView (see UIAlertView)
 *	@param	message	The message of the AlertView (see UIAlertView)
 *	@param	dismissButtonTitle	The title for the only button, acting as a "cancel" button
 *
 *  @note This is a commodity method, equivalent of calling 
 *   showAlertWithTitle:cancelButton:otherButtons:buttonHandler: with otherButtons and buttonHandler set to nil.
 *  @note This method has no OHAlertViewButtonHandler parameter as it is intended to be used
 *        to display simply informational alerts.
 */
+(void)showAlertWithTitle:(NSString *)title
                  message:(NSString *)message
            dismissButton:(NSString *)dismissButtonTitle;

/**
 *	Create a new AlertView. Designed initializer.
 *
 *	@param	title	The title of the AlertView (see UIAlertView)
 *	@param	message	The message of the AlertView (see UIAlertView)
 *	@param	cancelButtonTitle	The title for the "cancel" button (see UIAlertView)
 *	@param	otherButtonTitles	A NSArray of NSStrings containing titles for the other buttons (see UIAlertView)
 *	@param	handler	The block that will be executed when the user taps on a button. This block takes:
 *          - The OHAlertView as its first parameter, useful to get the firstOtherButtonIndex from it for example
 *          - The NSInteger as its second parameter, representing the index of the button that has been tapped
 *	@return	The newly created AlertView. use the -show method of UIAlertView then to display it on screen.
 */
-(instancetype)initWithTitle:(NSString *)title
                     message:(NSString *)message
                cancelButton:(NSString *)cancelButtonTitle
                otherButtons:(NSArray *)otherButtonTitles
               buttonHandler:(OHAlertViewButtonHandler)handler;

/////////////////////////////////////////////////////////////////////////////


/**
 *	Shows the AlertView that will be dismissed after timeoutInSeconds seconds (if no button is tapped before),
 *     by simulating a tap on the timeoutButtonIndex button after this delay.
 *
 *	@param	timeoutInSeconds	The number of seconds to wait before dismissing the AlertView
 *	@param	timeoutButtonIndex	The index of the button to simulate the tap on when the timeout reaches zero
 *	@param	countDownMessageFormat	A format string containing a %lu placeholder to customize the countdown message displayed in the alert.
 *        For example one may use @"(Alert dismissed in %lus)".
 *        If nil, no countdown message is added to the alert message.
 */
-(void)showWithTimeout:(unsigned long)timeoutInSeconds
    timeoutButtonIndex:(NSInteger)timeoutButtonIndex
  timeoutMessageFormat:(NSString*)countDownMessageFormat; // use "%lu" for the countdown value placeholder

@end
