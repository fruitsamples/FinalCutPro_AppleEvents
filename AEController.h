/*

    File: AEController.h
Abstract: UI controller class for AEDialog.nib
 Version: 1.2

Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
Inc. ("Apple") in consideration of your agreement to the following
terms, and your use, installation, modification or redistribution of
this Apple software constitutes acceptance of these terms.  If you do
not agree with these terms, please do not use, install, modify or
redistribute this Apple software.

In consideration of your agreement to abide by the following terms, and
subject to these terms, Apple grants you a personal, non-exclusive
license, under Apple's copyrights in this original Apple software (the
"Apple Software"), to use, reproduce, modify and redistribute the Apple
Software, with or without modifications, in source and/or binary forms;
provided that if you redistribute the Apple Software in its entirety and
without modifications, you must retain this notice and the following
text and disclaimers in all such redistributions of the Apple Software.
Neither the name, trademarks, service marks or logos of Apple Inc. may
be used to endorse or promote products derived from the Apple Software
without specific prior written permission from Apple.  Except as
expressly stated in this notice, no other rights or licenses, express or
implied, are granted by Apple herein, including but not limited to any
patent rights that may be infringed by your derivative works or by other
works in which the Apple Software may be incorporated.

The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.

IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

Copyright (C) 2009 Apple Inc. All Rights Reserved.


*/ 

#import <Cocoa/Cocoa.h>

// These values have to match the 'Identifier' associated with the tabs in AEDialog.nib
enum {
	tabOpen = 1,
	tabClose = 2,
	tabGet = 3,
	tabSend = 4,
	tabUUID = 5,
	tabFind = 6,
	tabUUIDs = 7,
	tabSave = 8,
	tabUnknown = 99
};

@interface AEController : NSWindowController {
		// general controls
	IBOutlet NSPopUpButton *event;				// menu of possible apple events
	IBOutlet NSTextField *fileLabel;			// file - label field
	IBOutlet NSPopUpButton *modeButton;			// file - mode
	IBOutlet NSPopUpButton *chooseButton;		// file - choose
	IBOutlet NSTextField *fileToSend;			// NB - used in conjunction with fileToSendURL
	IBOutlet NSTabView *tabView;				// hidden tabs to show only the controls we need

		// tab - open
	IBOutlet NSTextField *mixedStateLabel;		// UpdateMediaFile - msg
	IBOutlet NSButton *ignoreDateButton;		// UpdateMediaFile - do we ignore mod date or not?		
		
		// tab - close
	IBOutlet NSButton *saveButton;				// CloseProj - do we save or not?

		// tab - save
	IBOutlet NSTextField *savePath;				// SaveAs - path to save as
	IBOutlet NSButton *overwriteButton;			// overwite existing?

		// tab - get
	IBOutlet NSTextField *xmlVersion;			// GetXML - which version
	IBOutlet NSButton *reformatButton;			// automatically reformat XML?
	IBOutlet NSTextField *uuidLabel;			// GetItemXML - UUID label
	IBOutlet NSTextField *uuidToGet;			// GetItemXML - UUID (as text)

		// tab - UUID
	IBOutlet NSTextField *uuidToActOn;			// OpenItem - UUID (as text)
	
		// tab - uuids
	IBOutlet NSTextView *uuidsToSelect;			// SelectItem(s) - UUIDs (as text)

		// tab - find (a whole lot of controls for searching)
	IBOutlet NSButton *logicButton;
	IBOutlet NSButton *omitButton1;
	IBOutlet NSPopUpButton *columnPopUp1;
	IBOutlet NSPopUpButton *matchPopUp1;
	IBOutlet NSTextField *stringToFind1;
	IBOutlet NSButton *omitButton2;
	IBOutlet NSPopUpButton *columnPopUp2;
	IBOutlet NSPopUpButton *matchPopUp2;
	IBOutlet NSTextField *stringToFind2;
	
	OSType		msgToSend;						// the event we will send
	NSURL		*fileURL;						// file URL - if we have one
	int			fileSendMode;					// sending an FSRef or a 'URL'

	BOOL		isProject;						// fileURL is project
	NSURL		*projFileURL;					// saved value of fileURL for projects
	NSString	*projString;					// saved value of fileToSend for "
	NSURL		*mediaFileURL;					// saved value of fileURL for media file
	NSString	*mediaString;					// saved value of fileToSend for "   "
}
- (void)addColumnItems:(NSPopUpButton *)button;
- (IBAction)clearProjectData:(id)sender;
- (IBAction)switchToPath:(id)sender;
- (IBAction)chooseFileToSend:(id)sender;
- (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo;
- (void)setSelectedFileURL:(NSArray *)newURL;
- (IBAction)setMsg:(id)sender;
- (IBAction)setSendMode:(id)sender;
- (IBAction)sendAppleEvent:(id)sender;

@end
