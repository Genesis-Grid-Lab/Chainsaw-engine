--local test = require ("ChainSawInput")

-- call once to init script
function TestScript.OnStart(self)
    self.Transform = self:Get(TRANSFORM)
    print("script started!")
end

-- update everyframe
function TestScript.OnUpdate(self, dt)
    --print("UPDATING")
    movex = Vec2(10, 0)
    pos = movex.x * 2

    --print("pos: ", pos)

    if Inputs.IsKey(Inputs.KEY_A) then
        --self.Transform.Translate.x = self.Transform.Translate.x - 5
    end
    if Inputs.IsKey(Inputs.KEY_D) then
        --self.Transform.Translate.x = self.Transform.Translate.x + 5
    end
    if Inputs.IsKey(Inputs.KEY_W) then
        --self.Transform.Translate.y = self.Transform.Translate.y - 5
    end
    if Inputs.IsKey(Inputs.KEY_S) then
        --self.Transform.Translate.y = self.Transform.Translate.y + 5
    end
end

-- call when entity is destroyed
function TestScript.OnDestroy(self)
    print("DESTROY", self.Entity)
end

-- call when mouse is down
function TestScript.OnMouseDown(self, button)
    print("mousedown: ", button)
end

-- call when key down
function TestScript.OnKeyDown(self, key)
    print("keydown: ", key)
end
