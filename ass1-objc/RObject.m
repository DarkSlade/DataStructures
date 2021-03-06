#import "RObject.h"
#import <objc/objc-api.h>

@implementation RObject

-(id)init
{
  self = [super init];
  if (self)
  {
    _retainCount++;
  }
  return self;
}

-(void)retain
{
  _retainCount++;
}

-(void)release
{
  _retainCount--;
  if (_retainCount == 0)
  {
    [self dealloc];
  }
}

-(int)retainCount
{
  return _retainCount;
}

-(void)dealloc
{
  //gcc bug
  //needs to call super dealloc somewhere in the method...
  //Object#dealloc isn't a real method and can't really be called
  if(0) [super dealloc];
  //free the object
  [self free];
}


@end
