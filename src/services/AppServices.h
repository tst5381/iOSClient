//
//  AppServices.h
//  ARIS
//
//  Created by David J Gagnon on 5/11/11.
//  Copyright 2011 University of Wisconsin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RootViewController.h"
#import "AppModel.h"
#import "MyCLController.h"
#import "Location.h"
#import "Game.h"
#import "Tab.h"
#import "Item.h"
#import "Plaque.h"
#import "Npc.h"
#import "Media.h"
#import "WebPage.h"
#import "Quest.h"
#import "ARISAppDelegate.h"
#import "Note.h"
#import "NoteTag.h"
#import "ARISConnection.h"
#import "ARISMediaLoader.h"

@interface AppServices : NSObject

+ (AppServices *)sharedAppServices;

- (void) retryFailedRequests;

//Player
- (void) loginUserName:(NSString *)username password:(NSString *)password userInfo:(NSMutableDictionary *)dict;
- (void) registerNewUser:(NSString*)userName password:(NSString*)pass firstName:(NSString*)firstName lastName:(NSString*)lastName email:(NSString*)email;
- (void) createUserAndLoginWithGroup:(NSString *)groupName;
- (void) uploadPlayerPic:(Media *)m;
- (void) updatePlayer:(int)user_id withName:(NSString *)name;
- (void) resetAndEmailNewPassword:(NSString *)email;
- (void) setShowPlayerOnMap;

//Game Picker
- (void) fetchNearbyGameListWithDistanceFilter:(int)distanceInMeters;
- (void) fetchAnywhereGameList;
- (void) fetchRecentGameListForPlayer;
- (void) fetchPopularGameListForTime:(int)time;
- (void) fetchGameListBySearch:(NSString *)searchText onPage:(int)page;

- (void) fetchOneGameGameList:(int)game_id;

//Fetch Player State
- (void) fetchAllPlayerLists;
- (void) fetchPlayerLocationList;
- (void) fetchPlayerQuestList;
- (void) fetchPlayerInventory;
- (void) fetchPlayerOverlayList;
- (void) fetchNpcConversations:(int)npc_id afterViewingPlaque:(int)plaque_id;

//Fetch Game Data (ONLY CALLED ONCE PER GAME!!)
- (void) fetchAllGameLists;
- (void) fetchGameMediaList;
- (void) fetchTabBarItems;
- (void) fetchGameOverlayList;
- (void) fetchGameNpcList;
- (void) fetchGameItemList;
- (void) fetchGamePlaqueList;
- (void) fetchGameWebPageList;

- (void) fetchNoteListPage:(int)page;
- (void) fetchNoteTagLists;
- (void) fetchNoteWithId:(int)noteId;

//Should only be called in the case of a media appearing in the game that didn't exist when the game was initially launched (eg- someone took a picture)
- (void) fetchMediaMeta:(Media *)m;
- (void) loadMedia:(Media *)m delegateHandle:(ARISDelegateHandle *)dh;

//Note Stuff
- (void) deleteNoteWithNoteId:(int)noteId;
- (void) dropNote:(int)noteId atCoordinate:(CLLocationCoordinate2D)coordinate;

- (void) uploadNote:(Note *)n;
- (void) addComment:(NSString *)c fromPlayer:(User *)p toNote:(Note *)n;

//Tell server of state
- (void) updateServerWithPlayerLocation;
- (void) updateServerLocationViewed:(int)locationId;
- (void) updateServerPlaqueViewed:(int)plaque_id fromLocation:(int)locationId;
- (void) updateServerItemViewed:(int)item_id fromLocation:(int)locationId;
- (void) updateServerWebPageViewed:(int)webPageId fromLocation:(int)locationId;
- (void) updateServerNpcViewed:(int)npc_id fromLocation:(int)locationId;
- (void) updateServerMapViewed;
- (void) updateServerQuestsViewed;
- (void) updateServerInventoryViewed;
- (void) updateServerPickupItem:(int)item_id fromLocation:(int)locationId qty:(int)qty;
- (void) updateServerDropItemHere:(int)item_id qty:(int)qty;
- (void) updateServerDestroyItem:(int)item_id qty:(int)qty;
- (void) updateServerInventoryItem:(int)item_id qty:(int)qty;
- (void) updateServerAddInventoryItem:(int)item_id addQty:(int)qty;
- (void) updateServerRemoveInventoryItem:(int)item_id removeQty:(int)qty;

- (void) updateServerGameSelected;
- (void) fetchQRCode:(NSString*)QRcodeId;
- (void) saveGameComment:(NSString*)comment titled:(NSString*)t game:(int)game_id starRating:(int)rating;
- (void) startOverGame:(int)game_id;

@end
